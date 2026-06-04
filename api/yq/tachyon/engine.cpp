////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "engine.hpp"

#include <yq/tachyon/app/Application.hpp>

namespace yq::tachyon::engine {
    AngleUnit   gAngleUnit  = AngleUnit::Degree;
    LengthUnit  gLengthUnit = LengthUnit::Centimeter;
    TimeUnit    gTimeUnit   = TimeUnit::Second;

    AngleUnit   angle_unit()
    {
        return gAngleUnit;
    }
    
    Meter       length_scale()
    {
        return scale_of(gLengthUnit);
    }
    
    LengthUnit  length_unit()
    {
        return gLengthUnit;
    }
    
    TimeUnit    time_unit()
    {
        return gTimeUnit;
    }
}
