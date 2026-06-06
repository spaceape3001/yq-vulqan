////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Entity3.hpp>
#include <yq/tachyon/api/Entity3Data.hpp>
#include <yq/tachyon/api/EntityMetaWriter.hpp>

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
