////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/PhysicsData.hpp>
#include <yq/tachyon/function/FNForce3M.hpp>
#include <yq/tachyon/typedef/force3.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {
    class Force³Snap : public PhysicsSnap {
        YQ_OBJECT_DECLARE(Force³Snap, PhysicsSnap)
    public:
        FNForce³M       force;
        
        Force³Snap();
        ~Force³Snap();
        static void init_meta();
    };
    
    class Force³Data : public PhysicsData {
        YQ_OBJECT_DECLARE(Force³Snap, PhysicsSnap)
    public:
        Force³Data();
        ~Force³Data();
        static void init_meta();
    };
}
