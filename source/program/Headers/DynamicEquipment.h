#pragma once
#include "gameActor.h"
#include <stddef.h>
enum class EquipmentUserType {
   None, Player, Enemy, Npc
};

struct EquipmentBaseComponent{
   void* mVtable;
   char* mReferencePath;
   void* mpDocument;
   gameActor* mpActor;
   ActorLink mUserLink;
   EquipmentUserType mUserType;
   bool undefined0;
   bool undefined1;
   bool undefine2;
   int mHoldAnimationType; // not int but it is a enum class
   bool undefine3;
   bool undefine4;
   bool undefine5;
   bool undefine6;
};

enum class EquipState{
   Unequipped, EquipedDrawn, EquipedSheathed, Thrown
};

struct EquipmentStateController{
   bool mFlags;
   bool undefined;
   bool undefined1;
   bool undefined2;
   EquipState mEquipmentState;
   EquipState mPreciousState;
   bool undefined3;
   bool undefined4;
   bool undefined5;
   bool undefined6;
   void* mpCurrent;
   void* mp1;
   void* mp2;
   void* mp3;
   void* mp4;
};
static_assert(sizeof(EquipmentStateController) == 0x38);

struct EquipmentUserComponent{
   gameComponentBase mBase;
   ActorLink dynamicEquipArr[8];
};


struct DynamicEquipment
{
   EquipmentBaseComponent mBase; //size in bytes: 0x48
   char pad[0x68];
   ActorLink mAttachmentLink; //size in bytes: 0x18
   char pad1[0x308];
   EquipmentStateController mStateController;// size in bytes: 0x48
   char pad2[0xfd];
   bool mIsPendingDrop; //size in bytes: 0x1
   bool undefined1;
   bool undefine2;
};
static_assert(offsetof(DynamicEquipment, mIsPendingDrop) == 0x505);

constexpr unsigned long infoPad = 0x52 - 0x18 - 0x10;
struct EquipmentControlState{ 
   char pad_00[0x18];
   ActorBase* mpActorBase;
   DynamicEquipment* equipment;
   char pad[infoPad];
   bool mFlag;
};
static_assert(offsetof(EquipmentControlState,mFlag)== 0x52);

struct WeaponComponent{
   DynamicEquipment mBase;
   char pad[0x28];
   ActorLink mUserLink;
};
static_assert(offsetof(WeaponComponent, mUserLink) == 0x530);
struct game__component__DynamicEquipmentParam{
   char pad[0x152];
   bool mIsDeathOnUnequipped;
};






using DynamicEquipFunc = gameActor* (DynamicEquipment*);
DynamicEquipFunc* getUser = nullptr;
using getDynamicEquipCompFunc = DynamicEquipment* (gameActor*);
getDynamicEquipCompFunc* getDynamicEquip = nullptr;

using WeaponComponentFunc = bool (WeaponComponent*);
WeaponComponentFunc* isBreakByThownAttack = nullptr;

using WeaponGetCompFunc = WeaponComponent* (gameActor*);
WeaponGetCompFunc* getWeapon = nullptr;



