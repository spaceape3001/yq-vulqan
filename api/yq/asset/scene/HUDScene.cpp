////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "HUDScene.hpp"
#include <yq/tachyon/api/SceneMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::HUDScene)

namespace yq::tachyon {
    HUDScene::HUDScene()
    {
    }
    
    HUDScene::~HUDScene()
    {
    }
    
    void HUDScene::init_meta()
    {
        auto w = writer<HUDScene>();
        w.description("HUD Scene");
    }
}
