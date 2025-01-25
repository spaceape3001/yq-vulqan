////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/typedef/clock.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon {
    class Frame;
    
    struct Context {
        //! Expected time for the snapshot
        unit::Second    time        = 0.;

        //! Our expected sim time delta (paused is 0., rewinding is negative)
        unit::Second    Δt          = 0.;
        
        //! Current clock rate (compared to real time, zero is single-step mode)
        double          overclock   = 1.;
        
        time_point_t    wall;                   //!< Wall clock time (start of cycle)
        
        unit::Second    Δwall;
        
        uint64_t        tick            = 0ULL;     //!< Thread tick number
        uint64_t        cycles          = 0ULL;     //!< Ticks in current stage (resets on pause/resume)
        
        //  we'll have tachyon startup map here?
    };
}
