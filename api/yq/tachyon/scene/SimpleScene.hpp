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
    
        SimpleScene();
        ~SimpleScene();
        static void init_meta();
        
    protected:
        void    snap(SceneSnap&) const;
    };
}
