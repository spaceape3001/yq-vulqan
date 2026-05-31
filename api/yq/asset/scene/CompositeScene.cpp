////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CompositeScene.hpp"
#include <yq/tachyon/api/SceneMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::CompositeScene)

namespace yq::tachyon {
    CompositeScene::CompositeScene()
    {
    }
    
    CompositeScene::~CompositeScene()
    {
    }
        
    void CompositeScene::init_meta()
    {
        auto w = writer<CompositeScene>();
        w.description("Composite Scene");
    }
}
