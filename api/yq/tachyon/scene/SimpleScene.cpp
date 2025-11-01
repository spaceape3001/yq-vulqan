////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SimpleScene.hpp"
#include <yq/tachyon/api/SceneMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::SimpleScene)

namespace yq::tachyon {
    SimpleScene::SimpleScene()
    {
    }
    
    SimpleScene::~SimpleScene()
    {
    }

    void    SimpleScene::snap(SceneSnap& sn) const
    {
        Scene::snap(sn);
        for(const TypedID& t : sn.children){
            if(t(Type::Camera))
                sn.cameras.push_back(t);
            if(t(Type::Light))
                sn.lights.push_back(t);
            if(t(Type::Rendered))
                sn.rendereds.push_back(t);
        }
    }
    
    void SimpleScene::init_meta()
    {   
        auto w = writer<SimpleScene>();
        w.description("Simple Scene, using child/parenting");
    }
}
