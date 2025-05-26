////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "BackgroundLayer.hpp"
#include <tachyon/api/LayerInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::BackgroundLayer)

namespace yq::tachyon {
    void BackgroundLayer::init_info()
    {
        auto w = writer<BackgroundLayer>();
        w.description("Background Layer");
    }
    
    BackgroundLayer::BackgroundLayer()
    {
    }
    
    BackgroundLayer::~BackgroundLayer()
    {
    }
}
