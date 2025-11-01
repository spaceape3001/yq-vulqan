////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/scene/SimpleScene.hpp>

namespace yq::tachyon {
    class BackgroundScene : public SimpleScene {
        YQ_TACHYON_DECLARE(BackgroundScene, SimpleScene)
    public:
        BackgroundScene();
        ~BackgroundScene();
        static void init_meta();
    };
}
