////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/scene/SimpleScene.hpp>

namespace yq::tachyon {
    class ForegroundScene : public SimpleScene {
        YQ_TACHYON_DECLARE(ForegroundScene, SimpleScene)
    public:
        ForegroundScene();
        ~ForegroundScene();
        static void init_meta();
    };
}
