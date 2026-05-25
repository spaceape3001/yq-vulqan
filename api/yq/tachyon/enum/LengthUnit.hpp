////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/MetaBinder.hpp>
#include <yq/units.hpp>
#include <functional>

namespace yq::tachyon {
    enum class LengthUnit {
        Centimeter,
        Foot,
        Inch,
        Kilometer,
        Meter
    };
    
    constexpr unit::Meter   scale_of(LengthUnit lu)
    {
        switch(lu){
        case LengthUnit::Centimeter:
            return 1_cm;
        case LengthUnit::Foot:
            return 1_ft;
        case LengthUnit::Inch:
            return 1_in;
        case LengthUnit::Kilometer:
            return 1_km;
        case LengthUnit::Meter:
            return 1_m;
        default:
            return 1_m;
        }
    }
}

YQ_TYPE_DECLARE(yq::tachyon::LengthUnit)

