#pragma once
#include <sead/container/seadListImpl.h>
#include <sead/thread/seadCriticalSection.h>
#include <sead/heap/seadHeap.h>
#include <sead/heap/seadExpHeap.h>
#include <sead/mc/seadDependencyWorkerMgr.h>
#include "FrameWork.h"
#include "ModuleMethodDep.h"
typedef  unsigned int uint;
struct ModuleSystem;
struct Task;
struct TaskBase;



struct TaskMgr{
    sead::CriticalSection mTaskListCS;
    FrameWork* mpFrameWork;
    void* mpPreparedThread;
};

struct vft_sead_task{

};

struct HeapArray{
    sead::Heap* mpHeapArray[4];
    bool isAdjustedArray[4];
    int primaryIndex;
};

static_assert(sizeof(HeapArray) == 0x28);

template <typename LinkTask>
struct OffSetList;

template <typename LinkTask>
struct ListNode{
    ListNode<LinkTask> *mpPrev;
    ListNode<LinkTask> *mpNext;
    TaskBase* mData;
    OffSetList<LinkTask>*mpList;  
};

template <typename LinkTask>
struct OffSetList{
    ListNode<LinkTask> *mpPrev;
    ListNode<LinkTask> *mpNext;
    int mCount;
    int mOffset;
};

struct TaskParameterBase{
    void* mvtable;
};
struct TaskClassId{
    void* mType;
    void* mID;
};

struct TaskBase{
    vft_sead_task* vft_seadTaskBase;
    sead::Heap* mHeap;
    sead::ListNode mHeapListNode;
    TTreeNode<TaskBase*> mTreeNode;
    sead::SafeString mName;
    TaskParameterBase* mpParam;
    unsigned int mInternalFlag;
    bool unk;
    bool unk1;
    bool unk2;
    bool unk3;
    ListNode<TaskBase*>mTaskListNode;
    HeapArray mHeapArray;
    TaskMgr* mpTaskMgr;
    int state; //enum
    int Tag;//enum


};
static_assert(offsetof(TaskBase,mpTaskMgr) == 0xa8);


struct Task{
    TaskBase mBase;
    MethodTreeNode mCalcNode;
    MethodTreeNode mDrawNode;
};

struct PauseContext{
    uint	mPauseMask0;
    uint	mPauseMask1;
    uint	mPauseMask2;
    uint	mPauseMask3;
};

struct PauseMgr{
    char pad[0x30];
    PauseContext mPauseCtx;
};

struct PauseMgr;
struct ModuleMethodMgr
{
    ISystemTaskCallback mBase;
    bool mIsInstanceSet;
    bool unk, unk1,unk2,unk3,unk4,unk5,unk6;
    PtrArray<Imodule> mModuleArray;
    MethodTreeNode* mMethodTreeNodeModuleCalc;
    DrawMethod_ mDrawMethodDraw2D ;
    DrawMethod_ mDrawMethodDrawTool2D;
    DrawMethod_ mDrawMethodDrawTool2DSuper;
    DrawMethod_ mDrawMethodDraw3DOpa;
    DrawMethod_ mmDrawMethodDraw3DXlu;
    PauseMgr mPauseMgr;
    void* unk_;
    sead::DependencyWorkerMgr* mpDependencyJobWorkerMgr;
    sead::DependencyLightJobQueue*  mpDependencyJobQueue;	
	sead::DependencyJobGraph*	mpSystemJobGraph;	
	sead::DependencyJobGraph*	mpBackgroundJobGraph;
	sead::DependencyJobGraph*	mpGSysCalcGraph	;
	sead::DependencyJobGraph*	mpGSysDrawGraph	;
    ModuleCalcParam* mpModuleCalcParam;
    sead::ExpHeap* mpGeneralHeap;
    uint	mCalcState;
    uint	unk_1;
    long	mSetBootupPackTime;
    bool    unk_2;	
    bool    unk_3;	
    ushort	unk_4;
    int	mCalcCounter;
};




class ModuleSystem{
public:
    Task mBase;
    ModuleMethodMgr mModuleMethodMgr;
};

struct SlotList{
    sead::ListImpl mList;
};


struct DelegateEvent{
    void* unk_Vft;
    bool unk;
    bool unk_1;
    bool unk_2;
    bool unk3;
    SlotList mSlotList;
};


//
// struct FrameWork
// {
//     void* mVft_Framework = nullptr;
//     bool mReserve;
//     bool unk;
//     bool unk_1;
//     bool unk_2;
//     bool unk_3;
//     bool unk_4;
//     bool unk_5;
//     bool unk_6;
//     void* mpResetParam;
//     DelegateEvent mResetEvent;
//     TaskMgr* mTaskMgr;

// };
using TaskMgrf = TaskMgr*(TaskMgr*);
static TaskMgrf* create = nullptr;

static ModuleSystem** s_MsInstance = nullptr;
using ModuleSystemFunc = void(ModuleSystem*,Task*);
static ModuleSystemFunc* ModuleSystemCtor = nullptr;
