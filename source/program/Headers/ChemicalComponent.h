#include "gameActor.h"

struct chemListNode{
    chemListNode *mpPrev;
    chemListNode *mpNext;
};

struct chemListImpl{
    chemListNode mStartEnd;
    int mCount;
};


struct chemOffsetList{
    chemListImpl mList;
    int mOffset;
};



struct ChemComp
{
    gameComponentBase mBase;
    char pad[0x20];
    chemOffsetList mOffsetList;
};
static_assert(offsetof(ChemComp,mOffsetList)== 0x40);








using getChemCompFunc = ChemComp*(gameActor*);
getChemCompFunc* getChemComp = nullptr;

using setFreezeFunc = void (ChemComp*,int, unsigned int);
setFreezeFunc* setFreeze = nullptr;

using setLightningFunc = void(ChemComp*,int, unsigned int);
setLightningFunc* setLightning = nullptr;

using requestIgniteFunc = void(ChemComp*,int, uint);
requestIgniteFunc* requestIgnite = nullptr;

using setElectrifyFunc = void(ChemComp*,int , uint);
setElectrifyFunc* setElectrify = nullptr;

using setDetonateFunc = void(ChemComp*,int, uint, float*);
setDetonateFunc* setDetonate = nullptr;//addr 0x0158b304

using isExplodedFunc = bool(ChemComp*,uint);
isExplodedFunc* isExploded = nullptr;

using setChemicalStateFunc = void(ChemComp*,int,uint);
setChemicalStateFunc* setChemicalState = nullptr;











struct ConditionCounter{
    float value;
    float current;
};

static constexpr ulong val = 0x7c - 0x4 - 0x4;

struct ChemicalInfo{
    int mIndex0;
    int mChmObjectIndex;// if it is 0 it affects Link(player)
    char pad[val];
    ConditionCounter mBurnTime; 
};
static_assert(offsetof(ChemicalInfo, mBurnTime) == 0x7c);

struct BufferChemInfo
{
    int somethingIwillNotUse;
    int _4bools;
    ChemicalInfo* chemInfo;
};
static_assert(sizeof(BufferChemInfo)== 0x10);

static constexpr ulong res11 = 0x140 - 0x20;

struct ConditionComponent{
    gameComponentBase mBase; //0x20
    char pad0[res11];
    BufferChemInfo chemInfoBuf;
};
static_assert(offsetof(ConditionComponent,chemInfoBuf) == 0x140);

using GetConditionComponentFunc = ConditionComponent*(gameActor*);
GetConditionComponentFunc* GetConditionComponent = nullptr; 
using condCountUpdateFunc = void(uint*,float, float*);
condCountUpdateFunc* update = nullptr;



struct ChemicalContact
{
   char pad[0x39];
   bool mDetonateReason;
   char pad1[0x7];
   uint activeState;
};

using chemContSetDetonateFunc = void(ChemicalContact*,bool);
chemContSetDetonateFunc *chemContSetDetonate = nullptr;