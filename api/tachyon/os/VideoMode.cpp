////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/os/VideoMode.hpp>
#include <GLFW/glfw3.h>

namespace yq::tachyon {
    VideoMode::VideoMode(const GLFWvidmode&g) : 
        size(g.width, g.height), 
        bits({ g.redBits, g.greenBits, g.blueBits}), 
        refresh_rate(g.refreshRate)
    {
    }
}
