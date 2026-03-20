////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/SpatialData.hpp>
#include <yq/tachyon/typedef/kinetic.hpp>

namespace yq::tachyon {
    struct KineticSnap : public SpatialSnap {
    };
    
    struct KineticData : public SpatialData {
    };
}
