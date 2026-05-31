////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/collision.hpp>

namespace yq::tachyon {
    struct CollisionSnap : public TachyonSnap {
    };
    
    struct CollisionData : public TachyonData {
    };
}
