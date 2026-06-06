////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/entity/Mass.hpp>
#include <yq/tachyon/entity/MassData.hpp>
#include <yq/tachyon/api/ModelMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class MassMeta::Writer : public ModelMeta::Writer<C> {
    public:
        Writer(MassMeta* layerInfo) : ModelMeta::Writer<C>(layerInfo)
        {
        }
        
        Writer(MassMeta& layerInfo) : Writer(&layerInfo)
        {
        }
    };

}
