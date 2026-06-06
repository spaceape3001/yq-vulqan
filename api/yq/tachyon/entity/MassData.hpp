////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/typedef/mass.hpp>

namespace yq::tachyon {
    struct MassSnap : public ModelSnap {
    };
    
    struct MassData : public ModelData {
    };
}
