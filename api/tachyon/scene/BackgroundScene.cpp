////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "BackgroundScene.hpp"
#include <tachyon/api/SceneInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::BackgroundScene)

namespace yq::tachyon {
    BackgroundScene::BackgroundScene()
    {
    }
    
    BackgroundScene::~BackgroundScene()
    {
    }
    
    void BackgroundScene::init_info()
    {
        auto w = writer<BackgroundScene>();
        w.description("Background Scene");
    }
}
