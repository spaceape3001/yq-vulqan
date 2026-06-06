////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/entity/CollisionData.hpp>
#include <yq/tachyon/typedef/moment3.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {
    struct Collision³Snap : public CollisionSnap {
        Collision³Snap();
        ~Collision³Snap();
    };
    
    struct Collision³Data : public CollisionData {
        Collision³Data();
        ~Collision³Data();
    };
}
