#pragma once
#include "Requests.h"

typedef unsigned int uint;
typedef long s64;
typedef unsigned long u64;
typedef uint8_t byte;
struct BinaryData{
    Buffer_<char>mStorage;
    int mSize;
    bool unk1,unk2,unk3,unk4;
};

struct GameDataBool{
    void* mVtable;
    uint mResetTypeValue;
    bool mIsModified;
    byte unk1,unk2,unk3;
    int mSaveFileIndex;
    bool mIsNeedUpdateSaveValue;
    bool mDefaultValue;
    bool mValue;
    bool mValueSave;
};
static_assert(sizeof(GameDataBool) == 0x18);

struct GameDataBoolArray{
    void* vft_gmd_GameDataBase;
    uint mResetTypeValue;
    bool mIsModified;
    byte unk1,unk2,unk3;
    uint mOriginalSize;
    int  mSaveFileIndex;
    bool mIsNeedUpdateSaveValue;
    bool mDefaultValue;
    byte unk4,unk5;
    int unk6;
    Buffer_<uint>mValue;
    Buffer_<uint>mValueSave;
};
struct GameDataInt{
    void*   mVtable;
    uint    mResetTypeValue;
    bool    mIsModified;
    byte    unk1,unk2,unk3;
    int     mSaveFileIndex;
    byte    mIsNeedUpdateSaveValue;
    byte    unk4,unk5,unk6;
    int     mDefaultValue;
    int     mValue;
    int     mValueSave;
    byte    unk7,unk8,unk9,unk10;
};
struct GameDataIntArr{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    byte    unk1,unk2,unk3;
    uint    mOriginalSize;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    int     mDefaultValue;
    Buffer_<int>mValue;
    Buffer_<int>mValueSave;
};
struct GameDataFloat{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    float   mDefaultValue;
    float   mValue;
    float   mValueSave;
    bool    unk7,unk8,unk9,unk10;
};
struct GameDataFloatArray{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    uint    mOriginalSize;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    float   mDefaultValue;
    Buffer_<float>mValue;
    Buffer_<float>mValueSave;
};
struct GameDataEnum{
    void*   mVtable;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    uint    mDefaultValue;
    uint    mValue;
    uint    mValueSave;
    bool    unk7,unk8,unk9,unk10;
    Buffer_<uint>mEnumValue;
};
struct GameDataEnumArray{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    uint    mOriginalSize;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    uint   mDefaultValue;
    Buffer_<uint>mValue;
    Buffer_<uint>mValueSave;
};
struct GameDataVector2{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    uint    mOriginalSize;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    sead::Vector2f mDefaultValue;
    sead::Vector2f mValue;
    sead::Vector2f mValueSave;
};

struct GameDataVector2Array{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    uint    mOriginalSize;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    sead::Vector2f mDefaultValue;
    bool    unk7,unk8,unk9,unk10;
    Buffer_<sead::Vector2f>mValue;
    Buffer_<sead::Vector2f>mValueSave;
};
struct GameDataVector3{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    sead::Vector3f mDefaultValue;
    sead::Vector3f mValue;
    sead::Vector3f mValueSave;
    bool    unk7,unk8,unk9,unk10;
};
struct GameDataVector3fArray{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    uint    mOriginalSize;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    sead::Vector3f mDefaultValue;
    Buffer_<sead::Vector3f>mValue;
    Buffer_<sead::Vector3f>mValueSave;
};
struct GameDataString16{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    sead::FixedSafeString<16>mDefaultValue;
    sead::FixedSafeString<16>mValue;
    sead::FixedSafeString<16>mValueSave;
};

struct GameDataString16Array{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    uint    mOriginalSize;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6,unk7,unk8,unk9,unk0xA;
    sead::FixedSafeString<16>mDefaultValue;
    Buffer_<sead::FixedSafeString<16>>mValue;
    Buffer_<sead::FixedSafeString<16>>mValueSave;
};
struct GameDataString32{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    sead::FixedSafeString<32>mDefaultValue;
    sead::FixedSafeString<32>mValue;
    sead::FixedSafeString<32>mValueSave;
};
struct GameDataString32Array{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    uint    mOriginalSize;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6,unk7,unk8,unk9,unk0xA;
    sead::FixedSafeString<32>mDefaultValue;
    Buffer_<sead::FixedSafeString<32>>mValue;
    Buffer_<sead::FixedSafeString<32>>mValueSave;
};
struct GameDataString64{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    sead::FixedSafeString<64>mDefaultValue;
    sead::FixedSafeString<64>mValue;
    sead::FixedSafeString<64>mValueSave;
};
struct GameDataString64Array{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    uint    mOriginalSize;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6,unk7,unk8,unk9,unk0xA;
    sead::FixedSafeString<64>mDefaultValue;
    Buffer_<sead::FixedSafeString<64>>mValue;
    Buffer_<sead::FixedSafeString<64>>mValueSave;
};

struct GameDataBinary{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    BinaryData mDefaultValue;
    BinaryData mValue;
};
struct GameDataBinaryArray{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    uint    mOriginalSize;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6,unk7,unk8,unk9,unk0xA;
    BinaryData mValue;
    BinaryData mValueSave;
};
struct GameDataUint{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    uint    mDefaultValue;
    uint    mValue;
    uint    mValueSave;
    bool    unk7,unk8,unk9,unk0xA;
};
struct GameDataUintArray{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    uint    mOriginalSize;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    uint    mDefaultValue;
    Buffer_<uint> mValue;
    Buffer_<uint> mValueSave;
};
struct GameDataInt64{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    s64     mDefaultValue;
    s64     mValue;
    s64     mValueSave;
};
struct GameDataInt64Array{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    uint    mOriginalSize;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6,unk7,unk8,unk9,unk0xA;
    s64    mDefaultValue;
    Buffer_<s64> mValue;
    Buffer_<s64> mValueSave;
};
struct GameDataUint64{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    u64     mDefaultValue;
    u64     mValue;
    u64     mValueSave;
};
struct GameDataUint64Array{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    uint    mOriginalSize;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6,unk7,unk8,unk9,unk0xA;
    u64     mDefaultValue;
    Buffer_<u64> mValue;
    Buffer_<u64> mValueSave;
};


struct GameDataWString16{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    sead::WFixedSafeString<16>mDefaultValue;
    sead::WFixedSafeString<16>mValue;
    sead::WFixedSafeString<16>mValueSave;
};
struct GameDataWString16Array{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    uint    mOriginalSize;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6,unk7,unk8,unk9,unk0xA;
    sead::WFixedSafeString<16>mDefaultValue;
    Buffer_<sead::WFixedSafeString<16>>mValue;
    Buffer_<sead::WFixedSafeString<16>>mValueSave;
};
struct GameDataWString32{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    sead::WFixedSafeString<32>mDefaultValue;
    sead::WFixedSafeString<32>mValue;
    sead::WFixedSafeString<32>mValueSave;
};
struct GameDataWString32Array{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    uint    mOriginalSize;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6,unk7,unk8,unk9,unk0xA;
    sead::WFixedSafeString<32>mDefaultValue;
    Buffer_<sead::WFixedSafeString<32>>mValue;
    Buffer_<sead::WFixedSafeString<32>>mValueSave;
};
struct GameDataWString64{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6;
    sead::WFixedSafeString<64>mDefaultValue;
    sead::WFixedSafeString<64>mValue;
    sead::WFixedSafeString<64>mValueSave;
};

struct GameDataWString64Array{
    void*   vft_gmd_GameDataBase;
    uint    mResetTypeValue;
    bool    mIsModified;
    bool    unk1,unk2,unk3;
    uint    mOriginalSize;
    int     mSaveFileIndex;
    bool    mIsNeedUpdateSaveValue;
    bool    unk4,unk5,unk6,unk7,unk8,unk9,unk0xA;
    sead::WFixedSafeString<64>mDefaultValue;
    Buffer_<sead::WFixedSafeString<64>>mValue;
    Buffer_<sead::WFixedSafeString<64>>mValueSave;
};
struct GameDataBoolExp{
    void* mvTable;
    Buffer_<BoolExpression>mExpressionArray;
};
struct GameDataBool64bitKey{
    u64 mHash;
    uint mResetTypeValue;
    bool mIsSet;
    char mSaveFileIndex;
    char mStateFlags;
    char mExtraByte;
};
