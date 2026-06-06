////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/entity/Collision.hpp>
#include <yq/tachyon/entity/CollisionData.hpp>
#include <yq/tachyon/api/ModelMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class CollisionMeta::Writer : public ModelMeta::Writer<C> {
    public:
        Writer(CollisionMeta* collisionInfo) : ModelMeta::Writer<C>(collisionInfo)
        {
        }
        
        Writer(CollisionMeta& collisionInfo) : Writer(&collisionInfo)
        {
        }
    };

}
