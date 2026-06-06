////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/enum/AngleUnit.hpp>
#include <yq/tachyon/enum/LengthUnit.hpp>
#include <yq/tachyon/enum/MassUnit.hpp>
#include <yq/tachyon/enum/TimeUnit.hpp>

namespace yq::tachyon::engine {
    AngleUnit   angle_unit();
    Meter       length_scale();
    LengthUnit  length_unit();
    MassUnit    mass_unit();
    TimeUnit    time_unit();
}
