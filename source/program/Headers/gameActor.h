#pragma once
#include <sead/prim/seadSafeString.h>
#include <sead/math/seadMatrix.h>
#include <sead/container/seadOffsetList.h>
#include <sead/container/seadObjList.h>
#include <sead/container/seadRingBuffer.h>
#include <sead/prim/seadFunction.h>
#include <sead/thread/seadCriticalSection.h>
#include <sead/prim/seadFunction.h>
#include "Headers/BlackBoard.h"
#include <math/seadVector.h>
#include <sead/heap/seadHeap.h>
#include "BlackBoard.h"
#include "loggers.hpp"
struct BaseProc;

    //mStatus:
    // free = 0, creating = 1,created  = 2 , created with  success = 3, failure = 4, canceled_for_swap = 5,canceled = 6, deleting = 9


struct _IFunction{
    void* mvTable;
    void* mpParent;
    void(*PlaceHolder)(...); 
    void(*PlaceHolder2)(...);// just to align the pad
};  




struct BaseProcWatcher{
    uint mStatus;
    uint undefined;
    BaseProc* mpBaseProc;
    sead::CriticalSection mCS;
};

            
constexpr unsigned long res_1c0 = 0x1b8 - 0x8 - 0x8 - 0x4 - 0x4 - 0x8;
struct BaseProcWatcher;
struct BaseProc{
    void* mVtable;
    sead::Heap* mHeap;
    int mBaseProcId;
    int _0x14;
    const char* mName;
    char pad0x1c0[res_1c0];
    BaseProcWatcher* mpWatcher;
    sead::FixedRingBuffer<unsigned short,33>mDependencyRing;

};
static_assert(offsetof(BaseProc,mDependencyRing) == 0x1c0);


constexpr unsigned long res_0x430 = 0x430 - 0x410 - 0x8;
struct BaseProcRequestQueueMgr;
struct BaseProcMgr{
    char pad[0x410];
    BaseProc* mpRootBaseProc;
    char pad1[res_0x430];
    BaseProcRequestQueueMgr* mpBaseProcRequestQueueMgr;
};
static_assert(offsetof(BaseProcMgr, mpBaseProcRequestQueueMgr) == 0x430);
BaseProcMgr** sBaseProcMgrInstance; //address 0x04722268


struct BaseProcWatcherRef{
    BaseProcWatcher* mBaseProcWatcher;
};


struct BaseProcLinkData{
    char pad[0x40];
    BaseProc* mpBaseProc;
    int mBaseProcLinkDataId;
};


struct CreateAndDeleteThread{
    char padThreadCauseDifferentSize[0xd4];//This should be sead::MainThread but its size is different 
    int unk;
    BaseProcRequestQueueMgr* mpRequestQueueMgr;
    _IFunction unk1;
    uint mAtomicFlags;
    uint unk2;
    sead::FixedSafeString<64>mLastOperationString;
    uint unk3;
    uint unk4;
};

struct BaseProcCreateRequest{
    sead::Heap* mpHeap;
    uint mQueueIndEX;
    uint unk;
    void* mpfActorFactoryCreation;

};
struct ResourceBinder{
    bool mStateFlag;
    bool mType;
    bool unk[2];

};
struct BaseProcInitArg{
    sead::SafeString mName;
    int CalcPrioEnum;
    int unk;
    BaseProcWatcherRef* mpWatcherRef;
    void* PreActorPartialConfig;
    unsigned long mInstanceHeapSixe;
    bool unk1;
    bool unk2[2];
    bool mIsFrameHeap;
    bool mIsAdjustdHeap;
    bool mIsInstanceHeapThread;
    short unk3;
    ResourceBinder mResrcBinderActor;
};


struct BaseProcRequestQueue{
    sead::PtrArray<BaseProcCreateRequest>mCreateRequest;
    int mRequiredCount;
    int mFinsihedCount;
    BaseProcInitArg* mInitArg;
    BaseProcWatcher* mpWatcher;
    sead::FixedSafeString<64>mName;
    _IFunction mCreateCallback;
    _IFunction mFinalizeCallback;
    unsigned long unk;
    uint unk1;
    uint mPriority;
    _IFunction mCalcPriorityCallback;
    sead::ExpHeap* mpInstanceHeap;
};



struct BaseProcRequestQueueMgr{
    sead::PtrArray<CreateAndDeleteThread>mCreateAndDeleteThreadArr;
    _IFunction mCreateProcFunction;
    _IFunction mDeleteProcFunction;
    BaseProcRequestQueue mCreateRequestQueueArray[3];
    BaseProcRequestQueue mDeleteRequestQueue;
    BaseProcCreateRequest mCreate;
    int mCountRequestQueue;
    int mMaxRequestQueue;
    sead::CriticalSection RequestQueueCS;
    uint mCreateFlags;
    uint unk;
};


struct BaseProcJob;


struct ActorLink{
    void* mVtable;
    BaseProcLinkData* mpBaseProcLinkData;
    int mBaseProcId;
    bool undefined;
    bool undefined2;
    char mRefArrayMas;
    bool undefined3;
};
static_assert(sizeof(ActorLink) == 0x18);

struct PtrArrayIActorComponent{
    int mCount;
    int mCapacity;
    void* mppArray;
};
constexpr long siz = sizeof(BaseProc);
struct ActorBase{
   BaseProc mBase;
	char pad_2b4[0x2b4 - sizeof(BaseProc)];
   sead::Vector3f mPosition;
};
static_assert(offsetof(ActorBase,mPosition) == 0x2b4);
constexpr unsigned long res101 = offsetof(ActorBase,mPosition);

struct ActorMgr{
    char pad[0x70];
    int mAtomicCountActor;
};


enum class TransformFlags : u8 {
            UsePosition = 1 << 0,
            UseRotation = 1 << 1,
            UseScale    = 1 << 2,
        };

constexpr unsigned long res58 = 0x58 - 0x40;


struct CreateActorArg{
    sead::Vector3<float>mPos{ 0.f, 0.f, 0.f };
    sead::Matrix33<float>mRotation{ 1.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 1.f };
    sead::Vector3<float> mScale{ 1.f, 1.f, 1.f };
    int _0xc;
    sead::SafeString mName;
    bool _0x48;
    bool _0x49;
    bool _0x50;
    bool _0x51;
    bool _0x52;
    bool _0x53;
    bool _0x54;
    bool _0x55;
    bool _0x56;
    bool _0x57;
    bool _0x58;
    bool _0x59;
    int _p_;
    bb::InitInfo<32>* blackboard_info = nullptr;
    bb::InitInfo<32>* _60 = nullptr;
    ActorBase* mpParent = nullptr;
    ActorBase* mpDependent = nullptr;
    ActorBase* mpCreator = nullptr;
    void* creator_rtti = nullptr;
    sead::Heap* instance_heap = nullptr;
    sead::TypedBitFlag<TransformFlags> mTransformFlag;

};
static_assert(offsetof(CreateActorArg,blackboard_info) == 0x58);
static_assert(offsetof(CreateActorArg,mpCreator) == 0x78);
static_assert(offsetof(CreateActorArg,mTransformFlag) == 0x90);


enum class CreatePriority : u32{
    Highest, High, Middle, Low, Lowest
};
struct PreActor;
struct ActorFile;
struct ActorInfo;

struct ActorSettings{
    ActorInfo* mpActorInfo;
    void* unk;
    int unk2;
    short unk3;
    bool unks[2];
    sead::CriticalSection mCS;
    int unk4;
    uint mInfoFlags;
};

struct ActorParam{
    int mCount;
    int mCapacity;
    ActorSettings* mpArray;
};
struct PreActorRenderer;

struct PreActorGroup{
    sead::Buffer<PreActor>mPreActorBuffer;
    int mPreActorCount;
    int mNonBancPreActorCount;
    uint mRefCount;
    uint unk;
 //  sead::OffsetList<int> mBancGroupList;
    int mOwnedLinkIndex;
    int mCHildLinkIndex;
    sead::PtrArray<PreActor> mPreActors;
    sead::Buffer<uint> unk_Array;
    uint mFlags;
    uint unk1;

};

struct PreActorBinder{
    ActorSettings* mpActorSettigs;
    PreActor*   mpPreActor;
};

struct PreActorMgr{
    void* mVtable;
    PreActorRenderer * mpPreActorRenderer;
    BaseProcJob* mpBaseProcJob;
    void* b[3];
    uint* mpActorHashArray;
    short* mpActorHashMap;
    int mActorCount;
    int mMaxActorMax;
    sead::CriticalSection mActorInfoCS;
    sead::Buffer<ActorInfo> mActorInfoArray;
    sead::Buffer<ActorSettings>mActorParamMutexInfoArray;
    sead::Buffer<PreActorBinder>mPreActorBinderArray;
    uint unk;
    bool unks[4];
    sead::Buffer<PreActorGroup>mStaticPreActorGroup;
    sead::Buffer<PreActorGroup>mExtraStaticPreActorGroup;
    sead::PtrArray<sead::PtrArray<PreActor>>MpreActorsGruop;
    //sead::ObjList<PreActor>mDynamicPreActorList;
    int unk2;
    sead::CriticalSection mPreActorListCS;
};  



struct PreActor{
    
};

enum ActorResult : u32 {
        FailedToAcquireWatcher = 0,
        _01 = 1,
        EmptyActorName = 2,
        FailedToCreatePreActor = 3,
        FailedToCreateBlackboard = 4,
        EmptyNameRef = 5,
        NoMatchingFactory = 6,
        FailedToAllocateRequest = 7,
        InvalidWatcher = 8,
    };

struct gameActor
{
    ActorBase mBase;
}; 

struct ActorReference{
    gameActor* mpBase;
    bool isValid;
};
struct IaActorComponent{
    uintptr_t vtable;
    char* safeString;
};
static_assert(sizeof(IaActorComponent) == 0x10);

struct gameComponentBase{
    IaActorComponent mBase;
    void* useless;//0x8
    gameActor* mpActor; //0x8
};
static_assert(sizeof(gameComponentBase) == 0x20);




using getLifeComponentFunc = void* (gameActor*);
inline getLifeComponentFunc* getLifeComponent = nullptr;
inline getLifeComponentFunc* getLifeComponent2 = nullptr;




using tryGetFunc = gameActor*(ActorLink*, ActorLink*);
tryGetFunc* tryGetGameActor = nullptr; //address 0x00753530

using BaseProcFunc = gameActor*(ActorLink*, BaseProc*);
BaseProcFunc* getIfDependecyExists = nullptr;


ActorMgr** globalActorMgr = nullptr;
using requestCreateActorAsyncFunc = bool (ActorMgr*, const sead::SafeString& ,const CreateActorArg&, BaseProcWatcherRef*,CreatePriority, PreActor*,ActorFile*,
                                            sead::IFunction<void>*, bool, ActorResult*,PreActor**);
requestCreateActorAsyncFunc* requestCreateActorAsync = nullptr;

using requestCreateActorSyncFunc =  bool (ActorMgr*,const sead::SafeString&,const CreateActorArg&,PreActor*,ActorInfo*,void*, int*);
requestCreateActorSyncFunc* requestCreateActorSync = nullptr; 

using getWatcherRefFunc = BaseProcWatcherRef* (sead::FixedRingBuffer<BaseProcWatcherRef, 30>*);
getWatcherRefFunc *getWatcherRefFromRingBuffer = nullptr;

using acquireProcFunc = BaseProc*(BaseProcWatcher* ,bool, ActorBase*);
acquireProcFunc* acquireProc = nullptr;

using isAwaitCreationFunc = bool (BaseProcMgr*, BaseProcWatcher*);
isAwaitCreationFunc* isAwaitCreation = nullptr;

using isValidWatcherFunc = bool (BaseProcWatcher*,ActorLink*, ActorBase*);
isValidWatcherFunc* isValidWatcher = nullptr;

using isSuccessFunc = bool (BaseProcWatcherRef*);
isSuccessFunc* isSuccess = nullptr;

using ForEachRequestFunc = bool (BaseProcRequestQueueMgr*,BaseProc*);
ForEachRequestFunc* ForEachRequest = nullptr;

using waitForCompletionFunc = bool (ResourceBinder);
waitForCompletionFunc* waitForCompletion = nullptr;
