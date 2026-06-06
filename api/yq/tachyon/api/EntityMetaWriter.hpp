////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Entity.hpp>
#include <yq/tachyon/api/EntityData.hpp>
#include <yq/tachyon/api/ModelMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class EntityMeta::Writer : public ModelMeta::Writer<C> {
    public:
        Writer(EntityMeta* entityInfo) : ModelMeta::Writer<C>(entityInfo)
        {
        }
        
        Writer(EntityMeta& entityInfo) : Writer(&entityInfo)
        {
        }
    };

}
