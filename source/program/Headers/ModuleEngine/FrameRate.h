//Vfr stands for Variable Frame Rate
#pragma once
#include "ModuleEngine.h"
#include <sead/container/seadRingBuffer.h>
#include <sead/heap/seadDisposer.h>
#include <cassert>
struct CoreCounter{
        float mDeltaFrame;
        float mDeltaTime;
        sead::FixedRingBuffer<int,3> mMultiplierIndexRingBuf;
       
    };
struct TimeSpeedMultiPlier{   
    float mValue;
    float mTarget;
};

struct VFRMgr{    
    float mDeltaFrame;
    float mDeltaTime;
    float mRawDeltaFrame;
    float mRawDeltaTime;
    CoreCounter mCounters[3];
    TimeSpeedMultiPlier mTimeSpeedMultipliers[16];
    float mBaseTimeSpeedRate;
    unsigned int mCoreAndIntervalMask;
    sead::IDisposer mStaticDisposer;
};
VFRMgr** VFRMgrInstance = nullptr;

using UpdateFunc = void (VFRMgr*,int);
extern UpdateFunc* VFRupdate;

struct PhysicsModule;

extern PhysicsModule** s_Module; 

using updateDeltaFrameFunc = void (float,PhysicsModule*,PauseContext*);
extern updateDeltaFrameFunc* updateDeltaFrame;

using updateTimeRateFunc = void (float, PhysicsModule*,PauseContext*);
extern updateTimeRateFunc* updateTimeRate;