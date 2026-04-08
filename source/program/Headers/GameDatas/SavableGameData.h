#pragma once
#include "UtilitiesBuffer.h"
#include "GameDatas.h"
#pragma pack(push, 1)

struct HashMapElement{
    unsigned int mHash;
    int mIndex;
};

struct HashMap{
    HashMapElement* mpArray;
    int mCount;
    int mMax;
};


#pragma pack(push, 1)
template <class Value>
struct ChangeRequest{
    Value mValue;
    byte unk,unk1,unk2;
    uint mHash;
};

#pragma pack(push, 1)
template <class T>
struct GameDataStore{
    void* mVtable;
    Buffer_<T> mFlagArray;
    HashMap mIndexMapArray;
};
#pragma pack(push, 1)
template <class T, class Value, class Log>
struct ChangeAbleGameDataStore{
    GameDataStore<T>mBase;
    Buffer_< ChangeRequest<Value> >mChangeRequestArray;
    uint mPendingRequestCount;
    byte unk,unk1,unk2, unk3;
    RingBuf<Log>mChangeLog;
    byte unk4,unk5,unk6, unk7;
};
#pragma pack(pop)

#pragma pack(push, 1)
template<class T, class Value,class Log>
struct SavableGameDataStore{
    ChangeAbleGameDataStore<T,Value,Log>mBase;
    uint mResetMask;
    bool mIsNeedUpdateSaveDataFlags;
    byte unk1,unk2,unk3;
};
#pragma pack(pop)

