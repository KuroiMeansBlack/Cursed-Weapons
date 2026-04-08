#pragma once
//#include "Document.h"
//#include "gameActor.h"
#include <stddef.h>


struct LifeMessage{
    int mLife;
    int max_life;
    int extra_life;
    int break_Life;
    unsigned short flags;
    bool somethingUndefined1;
    bool somethingUndefined2;
};
struct LifeGameDataSync{
    void* mVtable;
    int mLife;
    uint mHash;
};

struct DamageCalcolatorExtension{
    char pad_0[0x8];
  //  gameActor* mpActor;
};
struct attackInfo{
    char pad[0xa7];
    bool undefined;
};
struct InternalDamageCalc{
    char pad[0x570];
    int* InternalBluePrint[3];
};


static constexpr ulong res0 = 0xfe0 - 0x20 - 0x8;
struct ExternalDamageCalc{
    char pad[0x20];
    DamageCalcolatorExtension* extension;
    char pad1[res0];
    attackInfo atkInfo;
};
struct DamageCalcolatorExtensionPlayer{
    DamageCalcolatorExtension mBase;
};
struct CalcolateInfo{
    char pad_0[0x8];
    int mLife;
    int mMaxLife;
};


static constexpr ulong res1 = 0x17f8 - 0x190 - 0x1088 - 0X588;
static constexpr ulong res2 = 0x1830 - 0x1088- 0X588 - res1 - 0x190 - 0x8; 
static constexpr ulong res3 = 0x18d0 - res2 - 0x1088- 0X588 - res1 - 0x190 - 0x8 - 0x8;
struct lifeComponent
{
    char pad[0x190];
    ExternalDamageCalc externalDmg; // lenght 0x1088
    InternalDamageCalc internalDmg; // 0x588
    char pad_2[res1];
    void* mpLifeParametersDocument; 
    char pad_3[res2];
    LifeGameDataSync* mpLifeGameDataSync;
    char pad_4[res3];
    CalcolateInfo mCalculationInfo;
};
static_assert(offsetof(lifeComponent,mpLifeGameDataSync) == 0x1830);
static_assert(offsetof(lifeComponent,mpLifeParametersDocument)== 0x17f8);
static_assert(offsetof(lifeComponent,mCalculationInfo) == 0x18d0);


struct game__component__life
{
    char _pad[0x5c];
    bool mIsDamagedWhileInvincible;
};

struct game__life__component{
    char pad[0x70];
    int mMaxLife;
};
struct game__life__DamageGlobalParam
{
    
};



using lifeReset = void (lifeComponent*);
lifeReset* resetLife = nullptr;


using lifeDeduct = void (lifeComponent*, int);
lifeDeduct* substractMaxLife = nullptr;//0x006abd84

using lifeParamFunc = int (game__life__component*);
lifeParamFunc* getMaxLife = nullptr;

using AffilationPlayerFunc = bool (ExternalDamageCalc*, char*);
AffilationPlayerFunc* isPlayerAffiliated = nullptr;
using setBreakLifeFunc = void (lifeComponent*,uint);
setBreakLifeFunc* setBreakLife = nullptr; 

using ApplyExternalFreezeShatterFunc = void (ExternalDamageCalc*, CalcolateInfo*);
ApplyExternalFreezeShatterFunc* ApplyExternalFreezeShatter = nullptr; //0x0064c1c8
using ApplyInternalFreezeShatterFunc = void(InternalDamageCalc*,CalcolateInfo*);
ApplyInternalFreezeShatterFunc*  ApplyInternalFreezeShatter = nullptr;