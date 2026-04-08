#include <sead/math/seadVector.h>
struct WorldManagerModule
{
    
};
WorldManagerModule** globalWmModule = nullptr;


using GetPlayerPosFunc         =    sead::Vector3<float>(WorldManagerModule*); 
GetPlayerPosFunc* getPlayerPos = nullptr; 