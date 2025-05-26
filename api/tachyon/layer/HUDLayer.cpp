////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "HUDLayer.hpp"
#include <tachyon/api/LayerInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::HUDLayer)

namespace yq::tachyon {
    void HUDLayer::init_info()
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
