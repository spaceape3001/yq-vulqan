////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Layer.hpp>

namespace yq::tachyon {
    class BackgroundLayer : public Layer {
        YQ_TACHYON_DECLARE(BackgroundLayer, Layer)
    public:
        static void init_meta();
        BackgroundLayer();
        ~BackgroundLayer();
    };
}
