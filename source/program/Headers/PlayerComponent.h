#pragma once
#include "gameActor.h"
template<typename T>
struct State{
    bool* mpState;
    T* mpValue;
};


struct PlayerComponent{
    gameComponentBase mBase;
    unsigned long activationStatus;
    unsigned long _28;
    State<uint64_t>mPlayerVirtualKey;
    State<uint64_t>mPlayerVirtualKeyHold;
    State<uint64_t>mPlayerVirtualKeyRelease;
};
using GetPlayerComponentFunc = PlayerComponent*(gameActor*);
using getForwardSpeedMpfFunc = float(PlayerComponent*);
using setForwardSpeedFunc = void (float v, PlayerComponent*);

GetPlayerComponentFunc* GetPlayerComponent = nullptr;
getForwardSpeedMpfFunc* getForwardSpeedMpf = nullptr;
setForwardSpeedFunc* setForwardSpeed = nullptr;