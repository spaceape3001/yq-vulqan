////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/EntityData.hpp>
#include <yq/tachyon/typedef/entity3.hpp>

namespace yq::tachyon {
    struct Entity³Snap : public EntitySnap {
        Entity³Snap();
        ~Entity³Snap();
    };
    
    struct Entity³Data : public EntityData {
        Entity³Data();
        ~Entity³Data();
    };
}
