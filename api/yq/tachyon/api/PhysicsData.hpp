////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/physics.hpp>

namespace yq::tachyon {
    struct PhysicsSnap : public TachyonSnap {
    };
    
    struct PhysicsData : public TachyonData {
    };
}
