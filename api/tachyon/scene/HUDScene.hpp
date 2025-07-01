////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/scene/SimpleScene.hpp>

namespace yq::tachyon {
    class HUDScene : public SimpleScene {
        YQ_TACHYON_DECLARE(HUDScene, SimpleScene)
    public:
        HUDScene();
        ~HUDScene();
        static void init_meta();
    };
}
