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
        
        //! Expected time for the snapshot
        double          time        = 0.;

        //! Our expected sim time delta (paused is 0., rewinding is negative)
        double          Δt          = 0.;
        
        //! Current clock rate (compared to real time, zero is single-step mode)
        double          overclock   = 1.;
        
        time_point_t    wall;                   //!< Wall clock time (start of tick-cycle)
        
        uint64_t        tick        = 0ULL;     //!< Thread Tick 

        Context(const Frame& _frame) : frame(_frame){}
        Context(Frame&&) = delete;
        Context(Context& cp) = default;
    };
}
