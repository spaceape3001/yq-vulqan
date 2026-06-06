////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/entity/EntityData.hpp>
#include <yq/tachyon/typedef/collision3.hpp>
#include <yq/tachyon/typedef/kinetic3.hpp>
#include <yq/tachyon/typedef/moment3.hpp>

namespace yq::tachyon {
    struct Entity³Snap : public EntitySnap {
    
        Collision³ID    collision;
        Kinetic³ID      kinetic;
        Moment³ID       moment;
    
        Entity³Snap();
        ~Entity³Snap();
    };
    
    struct Entity³Data : public EntityData {
        Entity³Data();
        ~Entity³Data();
    };
}
