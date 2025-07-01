////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "HUDLayer.hpp"
#include <tachyon/api/LayerMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::HUDLayer)

namespace yq::tachyon {
    void HUDLayer::init_meta()
    {
        auto w = writer<HUDLayer>();
        w.description("HUD Layer");
    }
    
    HUDLayer::HUDLayer()
    {
    }
    
    HUDLayer::~HUDLayer()
    {
    }
}
