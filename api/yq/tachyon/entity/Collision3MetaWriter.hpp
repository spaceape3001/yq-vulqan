////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/entity/Collision3.hpp>
#include <yq/tachyon/entity/Collision3Data.hpp>
#include <yq/tachyon/entity/CollisionMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Collision³Meta::Writer : public CollisionMeta::Writer<C> {
    public:
        Writer(Collision³Meta* myInfo) : CollisionMeta::Writer<C>(myInfo)
        {
        }
        
        Writer(Collision³Meta& myInfo) : Writer(&myInfo)
        {
        }
    };

}
