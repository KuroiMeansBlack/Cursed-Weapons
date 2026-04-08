#pragma once
#include <stddef.h>
#include <sead/container/seadRingBuffer.h>
#include "DynamicEquipment.h"
#include "GameDataMgr.h"
#include "gameActor.h"
#include "math/seadVector.h"
typedef unsigned int  uint;


enum class PouchCategory{
    Weapon,Bow,Arrow,Shield,Armor,Material,Food,SpecialParts,KeyItem,Rupee,
    Grain, SpecialPower
};
enum class PouchTab {
    Armor, Bow, Shield, Weapon, Material, Food, SpecialParts, KeyItem, System
};
enum class ModifierType {
    None, AttackUp, AttackUpPlus, DurabilityUp, DurabilityUpPlus, FinishBlow, LongThrow, RapidFire, ThreeWayZoom, FiveWay, GuardUp, GuardUpPlus
};
struct EquippedItem
{
    int mSortPattern;
    PouchCategory category;
    int mIndex;

};

struct PouchData{
    StructHandle mWeaponStruct;
    StructHandle mBowStruct;
    StructHandle mArrowStruct;
    StructHandle mShieldStruct;
    StructHandle mArmorStruct;
    StructHandle mMaterialStruct;
    StructHandle mFoodStruct;
    StructHandle mSpecialParts;
    StructHandle mKeyItemStruct;
    StructHandle mRupeeStruct;
    StructHandle mGrainStruct;
    StructHandle mSpecialPowerStruct;
};


struct DroppedItem{
    BaseProcWatcherRef mWatcherRef;
	PouchCategory mCategory;
	sead::Vector3f mRotatation;
	bool mEquipedAndSync;
	bool mEquipedInPouch;
	bool unk[2];
	int mLife;
	int mCombinedExtraLife;
	int mCombinedRecordExtraLife;
	int mModifier;
	int mModifierValue;
	sead::SafeString mCombinedActorName;
	int mCombinedLife;
	int unk_var;
	ActorLink mActorLink;
};



constexpr ulong res00 = 0x6f0 - 0x1b4 - 0x180 - 0x48 - 0x8 - 0x8 - 0x4 ;
struct PouchMgr{
    void* mVtable;//0x8
    PouchData mPouch[2]; //0x8
    int PouchIndex;//0x4
    PouchTab pouchTab; //0x4
    int mActivePouchIndices[9]; //0x24
    int mActivePouchRowIndices[9];//0x24
    char pad_0xff[440];
    char pad_00 [res00];
    sead::FixedRingBuffer<BaseProcWatcherRef,30> mPouchMaterialWatchers;
	void* unk2;
	void* unk3;
	sead::FixedRingBuffer<DroppedItem,54>mDroppedItems;  
    
};

static_assert(offsetof(PouchMgr,mPouchMaterialWatchers) == 0x6f0); 
static_assert(offsetof(PouchMgr,mDroppedItems) == 0x808);

struct PouchComponent
{
   gameComponentBase mBase;
   ActorLink mActorLink;
   PouchMgr* mpPouchMgr;
};

PouchMgr** globalPouchMgrInstance = nullptr; // address 0x046cbc98




using removeFromPouchFunc = void(PouchMgr*, PouchCategory, int, int, uint, PouchTab );
removeFromPouchFunc* removeFromPouch = nullptr; // 0x015d1fc8

using getPouchIndexFunc =int (PouchMgr*,int*, const char**,PouchCategory);
getPouchIndexFunc* getPouchIndex = nullptr;

using AddToPouchFun = bool (PouchMgr* self, const char** actor_name, const char** attachment_name, PouchCategory category,
                                    int count, bool set_is_get, int unk, bool is_equip, ModifierType modifier, int modifier_value,
                                    int life, int attachment_life, int attachment_extra_life, int record_extra_life, int* out_index, bool increment_ms_counter);
AddToPouchFun* addToPouch = nullptr;

using extractFromPouchFunc = bool(PouchMgr*,PouchCategory category,uint itemIndex,uint p4,int p5,int p6);
extractFromPouchFunc* extractFromPouch = nullptr;

using getPouchStructHandleFunc = StructHandle* (PouchMgr*,PouchCategory);
getPouchStructHandleFunc* getPouchStructHandle = nullptr;

using updatePouchGameDataFunc = void (PouchMgr*,PouchCategory);
updatePouchGameDataFunc* updatePouchGameData = nullptr;


using getPouchStockNumFunc = int(PouchMgr*,const char**, bool);
getPouchStockNumFunc* getPouchStockNum = nullptr;

using getPouchCountFunc = int(PouchMgr*, PouchCategory);
getPouchCountFunc* getPouchCount = nullptr;

using getEmptySlotIndexFunc = int (PouchMgr*,PouchCategory);
getEmptySlotIndexFunc* getEmptySlotIndex = nullptr;
//scrapFromPouch
 
using getWatcherFromDroppedRingBufferFun= BaseProcWatcherRef* (sead::FixedRingBuffer<DroppedItem,54>*);
getWatcherFromDroppedRingBufferFun* getWatcherFromDroppedRingBuffer = nullptr; 

