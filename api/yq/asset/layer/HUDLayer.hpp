////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Layer.hpp>

namespace yq::tachyon {
    class HUDLayer : public Layer {
        YQ_TACHYON_DECLARE(HUDLayer, Layer)
    public:
        static void init_meta();
        HUDLayer();
        ~HUDLayer();
    };
}
