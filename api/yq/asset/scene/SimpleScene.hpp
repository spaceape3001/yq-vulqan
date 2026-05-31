////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Scene.hpp>

namespace yq::tachyon {
    class SimpleScene : public Scene {
        YQ_TACHYON_DECLARE(SimpleScene, Scene)
    public:
    
        using Param = Scene::Param;
    
        SimpleScene();
        SimpleScene(const Param&);
        ~SimpleScene();
        static void init_meta();
        
    protected:
        void    snap(SceneSnap&) const;
    };
}
