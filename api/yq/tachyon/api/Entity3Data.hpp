////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/EntityData.hpp>
#include <yq/tachyon/typedef/collision.hpp>
#include <yq/tachyon/typedef/entity3.hpp>
#include <yq/tachyon/typedef/kinetic3.hpp>
#include <yq/tachyon/typedef/spatial3.hpp>

namespace yq::tachyon {
    struct Entity³Snap : public EntitySnap {
    
        CollisionID     collision;
        Kinetic³ID      kinetic;
    
        Entity³Snap();
        ~Entity³Snap();
    };
    
    struct Entity³Data : public EntityData {
        Entity³Data();
        ~Entity³Data();
    };
}
