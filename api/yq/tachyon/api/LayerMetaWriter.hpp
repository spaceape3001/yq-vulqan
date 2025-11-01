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
    class LayerMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(LayerMeta* layerInfo) : TachyonMeta::Writer<C>(layerInfo)
        {
        }
        
        Writer(LayerMeta& layerInfo) : Writer(&layerInfo)
        {
        }
    };

}
