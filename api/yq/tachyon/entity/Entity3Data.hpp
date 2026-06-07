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
    class Entity³Snap : public EntitySnap {
        YQ_OBJECT_DECLARE(Entity³Snap, EntitySnap)
    public:
    
        TypedID         collision;
        TypedID         kinetic;
        TypedID         moment;
    
        Entity³Snap();
        virtual ~Entity³Snap();
        static void init_meta();
    };
    
    class Entity³Data : public EntityData {
        YQ_OBJECT_DECLARE(Entity³Data, EntityData)
    public:
    
        Entity³Data();
        virtual ~Entity³Data();
        static void init_meta();
    };
}
