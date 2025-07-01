////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CompositeScene.hpp"
#include <tachyon/api/SceneMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::CompositeScene)

namespace yq::tachyon {
    CompositeScene::CompositeScene()
    {
    }
    
    CompositeScene::~CompositeScene()
    {
    }
        
    void CompositeScene::init_info()
    {
        auto w = writer<CompositeScene>();
        w.description("Composite Scene");
    }
}
