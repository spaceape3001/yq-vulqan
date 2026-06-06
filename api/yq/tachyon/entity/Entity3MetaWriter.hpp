////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/entity/Entity3.hpp>
#include <yq/tachyon/entity/Entity3Data.hpp>
#include <yq/tachyon/entity/EntityMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Entity³Meta::Writer : public EntityMeta::Writer<C> {
    public:
        Writer(Entity³Meta* myInfo) : EntityMeta::Writer<C>(myInfo)
        {
        }
        
        Writer(Entity³Meta& myInfo) : Writer(&myInfo)
        {
        }
    };

}
