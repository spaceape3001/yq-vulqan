////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/clock.hpp>

namespace yq::tachyon {
    class Frame;
    
    struct Context {
        //! Previous tick
        const Frame&    frame;
        
        //! Sim time
        double          time        = 0.;

        //! Our expected sim time delta (paused is 0., rewinding is negative)
        double          Δt          = 0.;
        
        //! Current clock rate (compared to real time, zero is single-step mode)
        double          overclock   = 1.;
        
        time_point_t    wall;                   //!< Wall clock time (start of tick-cycle)
        
        uint64_t        tick        = 0ULL;     //!< Thread Tick 

        Context(){}
        Context(Context& cp) : 
            frame(cp.frame), 
            time(cp.time),
            Δt(cp.Δt) 
            overclock(cp.overclock),
            wall(cp.wall),
            tick(cp.tick)
        {}
    };
}
