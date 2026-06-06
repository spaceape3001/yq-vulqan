////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/typedef/mass.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {
    struct MassSnap : public ModelSnap {
        Kilogram        mass{};
    };
    
    struct MassData : public ModelData {
    };
}
