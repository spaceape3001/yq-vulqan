////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "HUDScene.hpp"
#include <tachyon/api/SceneInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::HUDScene)

namespace yq::tachyon {
    HUDScene::HUDScene()
    {
    }
    
    HUDScene::~HUDScene()
    {
    }
    
    void HUDScene::init_info()
    {
        auto w = writer<HUDScene>();
        w.description("HUD Scene");
    }
}
