#pragma once
#include <sead/prim/seadSafeString.h>
#include <sead/prim/seadDelegate.h>
#include <sead/framework/seadMethodTree.h>
#include <sead/heap/seadHeap.h>
#include <sead/gfx/seadDrawMethod.h>
#include <sead/heap/seadDisposer.h>
#include <sead/thread/seadCriticalSection.h>    

struct DrawMethod_{
    sead::IDisposer mBase;
    sead::SafeString mName;
    unsigned int unk_00,unk_01,unk_02,unk_03;
    sead::DelegateBase<void*,char*,sead::DrawMethod> mDrawDelegate;
};


struct DeltaInfo{
    float mDeltaTime;
    float MdeltaFrame;
};

struct PauseContext;
struct CalcParam{
    DeltaInfo mDeltaInfo;
    PauseContext* mpPauseCtx;
};

struct ModuleCalcParam{
    CalcParam mBase;
    void* mp__unk;
};
struct MethodTreeNode;

struct TreeNode{
    TreeNode* mpParent;
    TreeNode* mpChild;
    TreeNode* mpNext;
    TreeNode* mpPrev;
};

template<typename U>
struct TTreeNode{
    TreeNode mTreeNode;
    MethodTreeNode* mData;
};


struct MethodTreeNode{
    sead::IDisposer mDisposer;
    TTreeNode<MethodTreeNode*> MtreeNode;
    sead::SafeString mName;
    sead::DelegateBase<void*,void*,sead::MethodTreeNode> mDelegate;
    sead::CriticalSection* mpCS;
    unsigned int mPrio;
    int pauseFlag;//enum
    sead::DelegateBase<void*,void*, sead::MethodTreeNode>* mpPauseEventDelegate; 
    void* mpUserId;
};



struct Imodule{
    void* vft_engine_module_Imodule;
    sead::SafeString mName;
    ModuleCalcParam* mpModuleCalc;
    unsigned int mNameHash;
};
struct vft_gys_ISystemTaskCallback;


struct ISystemTaskCallback{
    vft_gys_ISystemTaskCallback* mVftTable;
};
template <typename T>
struct PtrArray{
    int mCount;
    int mMax;
    T* mppArray;
};
