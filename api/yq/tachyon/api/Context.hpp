////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Tristate.hpp>
#include <yq/tachyon/api/StdThread.hpp>
#include <yq/tachyon/typedef/clock.hpp>
#include <yq/tachyon/typedef/use_thread.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon {
    class Frame;
    
    struct Context {
        
        Tristate        edit_mode   = Tristate::Inherit;

        //! Current clock rate (compared to real time, zero is single-step mode)
        double          overclock   = 1.;

        bool            paused      = false;

        struct {
            use_thread_t    kinetic;
            use_thread_t    model;
            use_thread_t    rendered;
            use_thread_t    spatial;
        } thread;

        uint64_t        tick        = 0ULL;     //!< Thread tick number

        //! Expected time for the snapshot
        unit::Second    time        = 0.;

        //! Our expected sim time delta (paused is 0., rewinding is negative)
        unit::Second    Δt          = 0.;
        
        time_point_t    wall;                   //!< Wall clock time (start of cycle)
        
        unit::Second    Δwall       = { 0. };
        
        //  we'll have tachyon startup map here?
        
    };
}
