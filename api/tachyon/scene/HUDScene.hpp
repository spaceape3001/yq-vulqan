////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Scene.hpp>

namespace yq::tachyon {
    class HUDScene : public Scene {
        YQ_TACHYON_DECLARE(HUDScene, Scene)
    public:
        HUDScene();
        ~HudScene();
        static void init_info();
    };
}
