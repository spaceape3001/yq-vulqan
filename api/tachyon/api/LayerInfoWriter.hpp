////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Layer.hpp>
#include <tachyon/api/LayerData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class LayerInfo::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(LayerInfo* layerInfo) : TachyonMeta::Writer<C>(layerInfo)
        {
        }
        
        Writer(LayerInfo& layerInfo) : Writer(&layerInfo)
        {
        }
    };

}
