struct PresentationInfo{
    int	    mTargetPresentInterval;
    int	    mStressedPresentInterval;
    float	mIntervalLenience;
    int	    unk_0;;
    int	    mFramerateChangeStepCount;
    int	    mPresentInterval;
    int	    mTemporaryTargetPresentInterval;
    int	    unk_1;
    int	    mFramerateChangeStepCounter;
    bool	mIsFixedPresentationInterval    ; 
};

struct FrameWork{
    char pad[0x248];
    PresentationInfo mPresentationInfo;
};

//Everthing related with the game engine and the framerate
    // INSTALLFUNCPTR(updateDeltaFrame,updateDeltaFrameFunc,0x007edc00);
    // INSTALLFUNCPTR(updateTimeRate,updateTimeRateFunc,0x007ee4c4);
    // INSTALLFUNCPTR(ModuleSystemCtor,ModuleSystemFunc,0x0103aac4);
    // INSTALLFUNCPTR(create, TaskMgrf,0x010e5bf0);
    // INSTALLFUNCPTR(VFRupdate,UpdateFunc,0x007ede6c);
    //INSTALLGLOBALINSTANCEPTRS(VFRMgrInstance,VFRMgr,0x04725bb8);
    //INSTALLGLOBALINSTANCEPTRS(s_Module,PhysicsModule,0x04726e78);
    //INSTALLGLOBALINSTANCEPTRS(s_MsInstance, ModuleSystem,0x04726e00);