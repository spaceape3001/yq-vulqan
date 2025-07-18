////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Mouse.hpp>

namespace yq::tachyon {
    class MouseGLFW : public Mouse {
        YQ_TACHYON_DECLARE(MouseGLFW, Mouse)
    public:
        MouseGLFW(const Param&p = Param());
        ~MouseGLFW();
        static void init_meta();
    };
}
