////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Collision.hpp>
#include <yq/tachyon/api/CollisionData.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class CollisionMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(CollisionMeta* collisionInfo) : TachyonMeta::Writer<C>(collisionInfo)
        {
        }
        
        Writer(CollisionMeta& collisionInfo) : Writer(&collisionInfo)
        {
        }
    };

}
