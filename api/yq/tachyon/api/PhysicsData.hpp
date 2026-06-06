////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/typedef/physics.hpp>
//#include <yq/tachyon/function/FNGravity3M.hpp>
//#include <yq/tachyon/function/FNWind3M.hpp>

namespace yq::tachyon {
    //class Frame;
    struct PhysicsSnap : public ModelSnap {
        bool    enabled = false;

        PhysicsSnap();
        ~PhysicsSnap();
    };
    
    struct PhysicsData : public ModelData {
    };
}
