////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ForegroundLayer.hpp"
#include <tachyon/api/LayerMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::ForegroundLayer)

namespace yq::tachyon {
    void ForegroundLayer::init_info()
    {
        auto w = writer<ForegroundLayer>();
        w.description("Foreground Layer");
    }
    
    ForegroundLayer::ForegroundLayer()
    {
    }
    
    ForegroundLayer::~ForegroundLayer()
    {
    }
}
