////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MScene.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Scene.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MScene)

namespace yq::tachyon {
    MScene::MScene(TypedID tid) : MTachyon(tid)
    {
    }
    
    MScene::~MScene()
    {
    }
    
    void MScene::init_meta()
    {
        auto w = writer<MScene>();
        w.description("Scene Qt Binder");
        w.manage<Scene>();
    }
}


#include "moc_MScene.cpp"
