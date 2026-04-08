#pragma once
#include <sead/math/seadVector.h>
#include <sead/prim/seadSafeString.h>
typedef unsigned int uint;
typedef long s64;
typedef unsigned long u64;

struct BoolExpression{
    uint mIndex;
    uint mHash;
    uint mOperator;
};
struct BoolArray{
    uint mHash;
    uint mValueAndIndex;
};
struct ArrayChangeLog{
    uint mHash;
    uint mIndex;
};
struct IntArray{
    int mValue;
    int mIndex;
    uint mHash;
    uint mIsAdditive;
};
struct FloatArray{
    float mValue;
    int mIndex;
    uint mHash;
    uint mIsAdditive;
};
struct EnumArray{
    uint    mValue;
    int	    mIndex;
    uint	mHash;
};
struct Vector2Array{
    sead::Vector2f mValue;
    int	    mIndex;
    uint	mHash;
};
struct Vector3Array{
    sead::Vector3f mValue;
    int	    mIndex;
    uint	mHash;
};
struct String16{
    sead::FixedSafeString<16>mValue;
    uint mHash;
};

struct String16Array{
    sead::FixedSafeString<16>mValue;
    int	    mIndex;
    uint	mHash;
};
struct String32{
    sead::FixedSafeString<32>mValue;
    uint mHash;
};
struct String32Array{
    sead::FixedSafeString<32>mValue;
    int	    mIndex;
    uint	mHash;
};
struct String64{
    sead::FixedSafeString<64>mValue;
    uint mHash;
};
struct String64Array{
    sead::FixedSafeString<64>mValue;
    int	    mIndex;
    uint	mHash;
};
template<class First,class Second>
struct Pair{
    First first;
    Second second;
    bool unk,unk2,unk3,unk4;
};

struct Binary{
    Pair<void const*,int>mValue;
    uint mHash;
    bool unk,unk2,unk3,unk4;
};
struct BinaryArr{
    Pair<void const*,int>mValue;
    int	    mIndex;
    uint	mHash;
};

struct Uint{
    uint mValue;
    uint mHash;
};
struct UintArr{
    uint mValue;
    uint mIndex;
    uint mHash;
};
struct Int64{
    s64 mValue;
    uint mHash;
};
struct Int64Arr{
    s64 mValue;
    uint mIndex;
    uint mHash;
};
struct Uint64{
    u64 mValue;
    uint mHash;
};
struct Uint64Arr{
    u64 mValue;
    uint mIndex;
    uint mHash;
};

struct WString16{
    sead::WFixedSafeString<16>mValue;
    uint mHash;
};

struct WString16Array{
    sead::WFixedSafeString<16>mValue;
    int	    mIndex;
    uint	mHash;
};
struct WString32{
    sead::WFixedSafeString<32>mValue;
    uint mHash;
};
struct WString32Array{
    sead::WFixedSafeString<32>mValue;
    int	    mIndex;
    uint	mHash;
};
struct WString64{
    sead::WFixedSafeString<64>mValue;
    uint mHash;
};
struct WString64Array{
    sead::WFixedSafeString<64>mValue;
    int	    mIndex;
    uint	mHash;
};

struct Bool64bitKey{
    bool mValue;
    bool unk,unk1,unk2;
    int mIndex;
};