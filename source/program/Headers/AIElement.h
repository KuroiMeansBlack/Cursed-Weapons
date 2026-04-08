#pragma once
#include "gameActor.h"
#include "types.h"

template <class T>
struct OutPutStorage{
    T* mpBuffer;
	T* mpStagingBuffer;
	ushort mBufferSize;
	ushort mStagingBufferSize;
	ushort mSyncState;
};


template <class T,class U, class V>
struct ParameterHandler{
    void* mVtable;
	
};
struct AIControllerActor{
	char pad[0x1f8];
	gameActor* mpActor;
}
struct Context{
	void* addr;
	AIControllerActor* mpController;
	
};
struct Element{
    void* mVtable;
	Context* mpContext;
	ParameterHandler<void*,bool,void*>* mpParamHandler;
	uint mCalcFlags;
	ushort mIndex;
    bool mChildNodeIndex;
	bool mPauseState;
};
