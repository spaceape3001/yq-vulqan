////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/PhysicsData.hpp>
#include <yq/tachyon/function/FNAcceleration3M.hpp>
#include <yq/tachyon/typedef/acceleration3.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {
    class Acceleration³Snap : public PhysicsSnap {
        YQ_OBJECT_DECLARE(Acceleration³Snap, PhysicsSnap)
    public:
        FNAcceleration³M       acceleration;
        
        Acceleration³Snap();
        ~Acceleration³Snap();
        static void init_meta();
    };
    
    class Acceleration³Data : public PhysicsData {
        YQ_OBJECT_DECLARE(Acceleration³Data, PhysicsData)
    public:
        Acceleration³Data();
        ~Acceleration³Data();
        static void init_meta();
    };
}
