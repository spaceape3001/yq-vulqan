////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/typedef/physics.hpp>

namespace yq::tachyon {
    struct PhysicsSnap : public ModelSnap {
        bool    enabled = false;

        PhysicsSnap();
        ~PhysicsSnap();
    };
    
    struct PhysicsData : public ModelData {
    };
}
