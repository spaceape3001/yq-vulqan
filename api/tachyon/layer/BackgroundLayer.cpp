////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "BackgroundLayer.hpp"
#include <tachyon/api/LayerMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::BackgroundLayer)

namespace yq::tachyon {
    void BackgroundLayer::init_meta()
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
