////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <chrono>
#include <yq/unit/declare.hpp>

namespace yq::tachyon {
    using clock_t                   = std::chrono::high_resolution_clock;
    using time_point_t              = clock_t::time_point;
    using duration_seconds_t        = std::chrono::duration<double, std::ratio<1,1>>;
    using duration_milliseconds_t   = std::chrono::duration<double, std::milli>;
    using duration_microseconds_t   = std::chrono::duration<double, std::micro>;
    using duration_nanoseconds_t    = std::chrono::duration<double, std::nano>;
    using duration_picoseconds_t    = std::chrono::duration<double, std::pico>;
    using duration_femtoseconds_t   = std::chrono::duration<double, std::femto>;
    using duration_attoseconds_t    = std::chrono::duration<double, std::atto>;
}
