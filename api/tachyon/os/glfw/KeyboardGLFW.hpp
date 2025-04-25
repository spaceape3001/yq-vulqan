////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Keyboard.hpp>
#include <tachyon/os/glfw/glfw.hpp>

namespace yq::tachyon {
    class KeyboardGLFW : public Keyboard {
        YQ_TACHYON_DECLARE(KeyboardGLFW, Keyboard)
    public:
        KeyboardGLFW(const Param&p={});
        ~KeyboardGLFW();
        static void init_info();
    };
}
