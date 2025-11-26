////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once


#include <yq/tachyon/asset/Material.hpp>
#include <yq/resource/ResourceMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class MaterialMeta::Writer : public ResourceMeta::Writer<C> {
    public:
        Writer(MaterialMeta* resourceInfoPtr) : ResourceMeta::Writer<C>(resourceInfoPtr)
        {
        }
        
        Writer(MaterialMeta& resourceInfoRef) : Writer(&resourceInfoRef)
        {
        }
    };
}
