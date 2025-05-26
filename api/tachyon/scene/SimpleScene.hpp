////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Scene3.hpp>

namespace yq::tachyon {
    class SimpleScene : public Scene {
        YQ_TACHYON_DECLARE(SimpleScene, Scene)
    public:
    
        SimpleScene();
        ~SimpleScene();
        static void init_info();
        
    protected:
        void    snap(SceneSnap&) const;
    };
}
