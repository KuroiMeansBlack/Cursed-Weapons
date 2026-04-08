#include "lib.hpp"
#include <stdlib.h>
#include <string.h>
#include <sead/prim/seadSafeString.h>
#include <math.h>
#include <sead/prim/seadTypedBitFlag.h>
#include <sead/prim/seadFunction.h>
#include <sead/container/seadRingBuffer.h>
#include <sead/time/seadTickTime.h>
#include "ModuleEngine/FrameRate.h"
#include <sead/thread/seadAtomic.h>
#include "DynamicEquipment.h"
#include "gameActor.h"
#include "lifeComponent.h"
#include "Pouch.h"
#include "GameDataMgr.h"
#include "ChemicalComponent.h"
#include "UISimpleInfo.h"


using exlCtx = exl::hook::InlineCtx;
using namespace exl::util::modules;
#define log Logging.Log
void Create_create_actor_arg(CreateActorArg*  create_actor_arg, BaseProc* base_proc){
    //Thanks to DT for the actor_spawn example :)
    ActorBase* player =  reinterpret_cast<ActorBase*>(base_proc);
    bb::InitInfo<32> init_info;
    create_actor_arg->mPos            = player->mPosition;
    create_actor_arg->mScale          = {1.f,1.f,1.f};
    create_actor_arg->blackboard_info = &init_info;
    create_actor_arg->mTransformFlag.set(TransformFlags::UsePosition);
    create_actor_arg->mTransformFlag.set(TransformFlags::UseScale);
}


static BaseProcWatcherRef* getRequestActorWatcher(BaseProc* base_proc ,PouchMgr* pouch_link){
	const sead::SafeString actor_name("BombFruit");
    CreateActorArg  create_actor_arg;
    Create_create_actor_arg(&create_actor_arg, base_proc);
    
	 BaseProcWatcherRef* watcherRef  = getWatcherRefFromRingBuffer(&(pouch_link->mPouchMaterialWatchers));
    
    requestCreateActorAsync(*globalActorMgr,actor_name,create_actor_arg,watcherRef,CreatePriority::High,
                                             nullptr,nullptr,nullptr,false,nullptr,nullptr);
	
    return watcherRef;
}


void breakLife(gameActor* game_actor){
   lifeComponent* life = reinterpret_cast<lifeComponent*>(getLifeComponent(game_actor));
   setBreakLife(life,4);
}
void executePlayerDeath(gameActor* game_actor){
	lifeComponent* life = reinterpret_cast<lifeComponent*>(getLifeComponent(game_actor));
	life->mpLifeGameDataSync->mLife = 0;
}

//~Reminder~  here i can use getPouchStructHandle/getStructStructIndex/getStructString64 Functions so i can output the removed weapon name 
static void RemoveRandomEquip(PouchMgr* pouch);// I need to create new SimpleInfo 

BaseProcWatcherRef* g_watcher = nullptr;


HOOK_DEFINE_TRAMPOLINE(PouchCalc){
	static void Callback(PouchMgr* p, long p2, long p3, long p4, NinFileDevice* nin){
			
		if(g_watcher!= nullptr){
        	if (isSuccess(g_watcher)){
		        log("watcher is valid");
			    if(g_watcher->mBaseProcWatcher){
					
					float arr[4];
                    BaseProc* watcher_proc =  acquireProc(g_watcher->mBaseProcWatcher,false,nullptr);
                    gameActor* g_actor = reinterpret_cast<gameActor*>(watcher_proc);
					if(g_actor){
						arr[0] = NAN;
						ChemComp* chemical = getChemComp(g_actor);
						if(chemical){
							setDetonate(chemical,2,0xffffffff,arr);
							g_watcher = nullptr;
						}
					}	
	            }
	        }
	    }
	    
		Orig(p,p2,p3,p4,nin);
    }
};	

HOOK_DEFINE_TRAMPOLINE(OnDeath){
    //I am getting the the BaseProc from the ActorLink cause when the weapon is thrown the baseProc id is -1(invalid owner)
    //so  DynamicEquipment::getUser won't work
    static void Callback(DynamicEquipment* _this, int flag){
        PouchMgr* pouch_hold      = *globalPouchMgrInstance;
        ActorLink* userLink       = &_this->mBase.mUserLink;
        BaseProc* base_proc       = userLink->mpBaseProcLinkData->mpBaseProc;
        gameActor* gActor         = reinterpret_cast<gameActor*>(base_proc);;
		
        Orig(_this,flag);
        if(!gActor){  
            log("gActor is null");
            return;
        }
	   //The watcher is valid at the 4th frame("Proccessed" by PouchMgr::Calc) after the function OnDeath is called
       g_watcher =  getRequestActorWatcher(base_proc,pouch_hold);
    }
};

extern "C" void exl_main(void *x0, void *x1)
{

    exl::hook::Initialize();
   // srand(time(nullptr));
    //-------------Defines----------------------
    #define INSTALLFUNCPTR(NAME, FUNCPTR, ADDR)\
        NAME = reinterpret_cast<FUNCPTR*>(GetTargetOffset(ADDR));\

    #define INSTALLGLOBALINSTANCEPTRS(NAME, PTR_PTR, ADR)\
        NAME =reinterpret_cast<PTR_PTR**>(GetTargetOffset(ADR));\
//------------------------GlobalVariables-------------------------------------
        
    INSTALLGLOBALINSTANCEPTRS(globalPouchMgrInstance,PouchMgr,0x046cbc98);
    INSTALLGLOBALINSTANCEPTRS( globalActorMgr, ActorMgr,0x04722920);
    INSTALLGLOBALINSTANCEPTRS(sBaseProcMgrInstance,BaseProcMgr,0x04722268);
    INSTALLGLOBALINSTANCEPTRS(GameUIModuleInstance,GameUIModule,0x046cd480);   
    INSTALLGLOBALINSTANCEPTRS(GameUIModuleInstance,GameUIModule,0x046cd480);
    //INSTALLGLOBALINSTANCEPTRS(GlobalGameDataMgr,GameDataMgr,0x04721b98);
    //INSTALLGLOBALINSTANCEPTRS(sceneModuleInstance, SceneModule,0x04728538);

//------------------------Functions-------------------------------------

    // Life
        
    INSTALLFUNCPTR(getLifeComponent,getLifeComponentFunc,0x00fa7f50); 
    INSTALLFUNCPTR(substractMaxLife,lifeDeduct,0x006abd84);
    //Pouch
    INSTALLFUNCPTR(getEmptySlotIndex,getEmptySlotIndexFunc,0x00cdc9b8);
    INSTALLFUNCPTR(removeFromPouch,removeFromPouchFunc,0x015d1fc8);
    // INSTALLFUNCPTR(getPouchIndex,getPouchIndexFunc,0x019a8138);
    //CHEMical
    INSTALLFUNCPTR(getChemComp,getChemCompFunc,0x0084986c);
    INSTALLFUNCPTR(setFreeze,setFreezeFunc,0x01596b60);
    INSTALLFUNCPTR(setLightning,setLightningFunc,0x015694ec);
    INSTALLFUNCPTR(setElectrify,setElectrifyFunc,0x009e34a0);
    INSTALLFUNCPTR(setBreakLife,setBreakLifeFunc,0x015f8e2c);
    INSTALLFUNCPTR(setDetonate,setDetonateFunc,0x0158b304);
    //Actors
    INSTALLFUNCPTR(requestCreateActorAsync,requestCreateActorAsyncFunc,0x00ab92cc);
    INSTALLFUNCPTR(getWatcherRefFromRingBuffer,getWatcherRefFunc,0x01a69238);
    INSTALLFUNCPTR(acquireProc, acquireProcFunc,0x00d5b5fc);
    INSTALLFUNCPTR(isSuccess,isSuccessFunc,0x00fc128c);
	//UISIMPLEINFO
    INSTALLFUNCPTR(RequestSimpleInfo,RequestSimpleInfoFun,0x00a13db0);
	
    
//------------------------HOOKS-------------------------------------    
    OnDeath::InstallAtOffset(0x015ab554);
	PouchCalc::InstallAtOffset(0x00cd3620);
    //ONLOADGAMESAVEDATA::InstallAtOffset(0x0110f210);
    //ISRAIN::InstallAtOffset(0x01d56d30);
    #undef INSTALLFUNCPTR
    #undef INSTALLGLOBALPTRS
}
extern "C" NORETURN void exl_exception_entry()
{
    /* Note: this is only applicable in the context of applets/sysmodules. */
    EXL_ABORT("Default exception handler called!");
}


