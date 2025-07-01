////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ForegroundScene.hpp"
#include <tachyon/api/SceneMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::ForegroundScene)

namespace yq::tachyon {
    ForegroundScene::ForegroundScene()
    {
    }
    
    ForegroundScene::~ForegroundScene()
    {
    }
    
    void ForegroundScene::init_meta()
    {
        auto w = writer<ForegroundScene>();
        w.description("Foreground Scene");
    }
}
