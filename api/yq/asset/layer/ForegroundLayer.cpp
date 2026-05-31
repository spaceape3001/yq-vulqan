////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ForegroundLayer.hpp"
#include <yq/tachyon/api/LayerMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::ForegroundLayer)

namespace yq::tachyon {
    void ForegroundLayer::init_meta()
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
