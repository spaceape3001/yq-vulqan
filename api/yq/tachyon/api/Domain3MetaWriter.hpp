////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Domain3.hpp>
#include <yq/tachyon/api/Domain3Data.hpp>
#include <yq/tachyon/api/DomainMetaWriter.hpp>

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
