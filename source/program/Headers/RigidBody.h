#pragma once
#include "gameActor.h"
struct SensorHitComponent
{
  gameComponentBase mBase;
};


struct SensorInfoBase
{
   void* mVtable;
   gameActor* mpActor; 
   int  undefined;
   bool  undefined1;
   bool  undefined2;
   bool  undefined3;
   bool  undefined4;
   ActorLink mActorLink;
};

struct RigidBodyBase
{
    char pad[0x110];
    SensorInfoBase* mpSensorInfo;
};

struct RigidBodyEntity
{
    RigidBodyBase mBase;
};

using RigidBodyActorFun = RigidBodyEntity* (ActorBase*);
RigidBodyActorFun* getMainRigidBody = nullptr;

using PhiveRigidBodyFunc = ActorLink*(RigidBodyEntity*);
PhiveRigidBodyFunc* getActorLink = nullptr;


