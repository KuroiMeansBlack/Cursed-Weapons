#pragma once

#ifdef NNSDK
#include <nn/os.h>
#endif

#include <basis/seadTypes.h>
#include <time/seadTickSpan.h>
#include <nn/os/os_tick.hpp>

namespace sead
{
/// A TickTime represents an instant in time.
class TickTime
{
public:
    TickTime() { setNow(); }

    u64 getTicks() const { return mTick; }

#ifdef NNSDK
    void setNow() { 
        mTick = nn::os::GetSystemTick().GetInt64Value(); 
        SEAD_ASSERT_MSG(mTick != 0xffffffffffffffff,"assert in SeadTickTime.h");
    }
#else
    void setNow();
#endif

    TickSpan diff(const TickTime& other) const { return s64(mTick - other.mTick); }
    TickSpan diffToNow() const { return TickTime().diff(*this); }
    
    TickTime& operator+=(const TickSpan& span)
    {
        mTick += span.toTicks();
        return *this;
    }

    TickTime& operator-=(const TickSpan& span)
    {
        mTick -= span.toTicks();
        return *this;
    }
    // my code
    operator u64() const {
        return getTicks();
    }
    //end of my code
private:
    u64 mTick;
};
}  // namespace sead
