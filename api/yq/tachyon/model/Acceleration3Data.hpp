////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/model/PhysicsData.hpp>
#include <yq/tachyon/function/FNAcceleration3M.hpp>
#include <yq/tachyon/typedef/acceleration3.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {
    struct Acceleration³Snap : public PhysicsSnap {
        FNAcceleration³M       acceleration;
        
        Acceleration³Snap();
        ~Acceleration³Snap();
    };
    
    struct Acceleration³Data : public PhysicsData {
        Acceleration³Data();
        ~Acceleration³Data();
    };
}
