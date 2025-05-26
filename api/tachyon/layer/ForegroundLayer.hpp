////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Layer.hpp>

namespace yq::tachyon {
    class ForegroundLayer : public Layer {
        YQ_TACHYON_DECLARE(ForegroundLayer, Layer)
    public:
        static void init_info();
        ForegroundLayer();
        ~ForegroundLayer();
    };
}
