#pragma once

#include <cstddef>
#include <sead/prim/seadSafeString.h>
#include <sead/container/seadTList.h>
enum class SimpleInfoType{
	    RicketyWeapon,
		RicketyShield,
		RicketyBow,
		BrokenWeapon,
		BrokenShield,
		BrokenBow,
		CouldNotPutWeapon,
		CouldNotPutShield,
		CouldNotPutBow,
		CouldNotPutFood,
		CouldNotPutArmor,
		CannotSetMorePin,
		CannotSetPinThere,
		EatenEquipment,
		RupeeShortage,
		MaterialsShortage,
		AttackedGerudoQueen,
		CannotBuildAutoBuilder,
		RicketyMasterSword,
		SleepMasterSword,
		WakeUpMasterSword,
		InaudibleToHorse,
		CannotComeHorse,
		ConnotGoAnyFurther,
		CannotSetPinHere,
		NotHaveWeaponForDisplay,
		NotHaveShieldForDisplay,
		NotHaveBowForDisplay,
		CannotKillTime,
		NoTimeForThat,
		CannotCook,
		ChangeWeapon,
		CannotCarryNow,
		CannotCarryHere,
		CannotPickUpMore,
		CannotBuyMore,
		CannotUseAmiiboToday,
		CannotUseHere,
		CannotIncreaseHeart,
		CannotDisplayWeapon,
		CannotDisplayBow,
		CannotDisplayShield,
		DropWeapon,
		DropShield,
		DropBow,
		CannotCopyWell,
		NotExistBluePrintDraft,
		CannotCallNow,
		NotHaveArrow,
		CannotExtractHere,
		CannotAttachAlreadyAttache,
		CannotAttachSpecialEquipment,
		CannotAttachNoEquipment,
		CannotDisplayMasterSword,
		CannotScraBuildBrokenMasterSword,
		CannotAttachMore,
		CannotExtractNow,
		ZonaniumShortage,
		BigZonaniumShortage,
		CannotBuildAutoBuilderTooNarrow,	
};
struct SimpleInfo{
	SimpleInfoType type;
	bool unk[4];
	sead::FixedSafeString<64> mMessage;
	sead::FixedSafeString<64> mSecondMessage;
};

struct UiSimpleInfoMgr{
    bool unk;
	bool mRequestableSimpleInfo;
	bool unk2[2];
	int unk3;
    SimpleInfo mInfo[8];
	float mOpenTimer0;
	float mOpenTimer1;	
};
struct fakeListNode{
    fakeListNode* mpNext;
	fakeListNode* mpPrev;
};
struct fakeListNodeImpl{
    fakeListNode mStartEnd;
	int mCount;
	
};
struct FakeTlist{
    fakeListNodeImpl mList;	
};
struct FileDevice;
template<class NodeType>
struct FakeTlistNode{
    fakeListNode mList;
    NodeType* mpFileDevice;
	FakeTlist* mpList;
};

struct FileDevice{
	void* archiveFileDeviceVtable;
    FakeTlistNode<FileDevice*>mListNode;
	sead::FixedSafeString<32>mDriveName;
	bool mPermission;
	bool unk[3];
	unsigned int mLastError;
};
constexpr inline unsigned long size = sizeof(FileDevice);

struct NinFileDevice{
	FileDevice mBase;
    char*  mMountPoint;
         
};
static_assert(sizeof(NinFileDevice) == 0x68);
struct GameUIModule{
	char pad[0x5c8];
    UiSimpleInfoMgr* mpUiSimpleInfoMgr;
	char pad1[(0xa38 -sizeof(pad)) - 0x8];
	NinFileDevice mSaveFileDevice;
};
static_assert(offsetof(GameUIModule,mSaveFileDevice)== 0xa38);
GameUIModule** GameUIModuleInstance = nullptr;     //046cd480 	

using RequestSimpleInfoFun = void (UiSimpleInfoMgr*,int number,sead::SafeString& actor_name, char* message);
RequestSimpleInfoFun* RequestSimpleInfo = nullptr; //00a13db0
