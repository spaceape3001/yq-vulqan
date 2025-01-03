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
    using duration_seconds_t        = std::chrono::duration<unit::Second, std::ratio<1,1>>;
    using duration_milliseconds_t   = std::chrono::duration<unit::Millisecond, std::milli>;
    using duration_microseconds_t   = std::chrono::duration<unit::Microsecond, std::micro>;
    using duration_nanoseconds_t    = std::chrono::duration<unit::Nanosecond, std::nano>;
    using duration_picoseconds_t    = std::chrono::duration<unit::Picosecond, std::pico>;
    using duration_femtoseconds_t   = std::chrono::duration<unit::Femtosecond, std::femto>;
    using duration_attoseconds_t    = std::chrono::duration<unit::Attosecond, std::atto>;
}
