////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/model/PhysicsData.hpp>
#include <yq/tachyon/function/FNForce3M.hpp>
#include <yq/tachyon/typedef/force3.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {
    struct Force³Snap : public PhysicsSnap {
        FNForce³M       force;
        
        Force³Snap();
        ~Force³Snap();
    };
    
    struct Force³Data : public PhysicsData {
        Force³Data();
        ~Force³Data();
    };
}
