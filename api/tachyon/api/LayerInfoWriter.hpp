////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Layer.hpp>
#include <tachyon/api/LayerData.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class LayerInfo::Writer : public TachyonInfo::Writer<C> {
    public:
        Writer(LayerInfo* layerInfo) : TachyonInfo::Writer<C>(layerInfo)
        {
        }
        
        Writer(LayerInfo& layerInfo) : Writer(&layerInfo)
        {
        }
    };

}
