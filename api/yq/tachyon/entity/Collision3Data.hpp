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
    class Collision³Snap : public CollisionSnap {
        YQ_OBJECT_DECLARE(Collision³Snap, CollisionSnap)
    public:
        Collision³Snap();
        virtual ~Collision³Snap();
        static void init_meta();
    };
    
    class Collision³Data : public CollisionData {
        YQ_OBJECT_DECLARE(Collision³Data, CollisionData)
    public:
        Collision³Data();
        ~Collision³Data();
        static void init_meta();
    };
}
