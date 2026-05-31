////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/physicsvk/api/Domain3.hpp>
#include <yq/physicsvk/api/Domain3Data.hpp>
#include <yq/physicsvk/api/DomainMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Domain³Meta::Writer : public DomainMeta::Writer<C> {
    public:
        Writer(Domain³Meta* sceneInfo) : DomainMeta::Writer<C>(sceneInfo)
        {
        }
        
        Writer(Domain³Meta& sceneInfo) : Writer(&sceneInfo)
        {
        }
    };

}
