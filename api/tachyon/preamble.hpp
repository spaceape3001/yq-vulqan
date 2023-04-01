////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Logging.hpp>

struct GLFWmonitor;
struct GLFWvidmode;
struct GLFWwindow;

namespace yq {

    namespace asset {
    }

    //! Namespace for our vulkan code... deliberately mispelled with a "Q"
    namespace vulqan {
    }
    
    namespace engine {
        class Viewer;
    }
    
    namespace tachyon {
        class   AppGLFW;
        struct  Joystick;
        class   Monitor;
        struct  VideoMode;
        class   Visualizer;
        class   Viewer;
        class   VqApp;
        struct  VqAppCreateInfo;
        
        using   AppCreateInfo  = VqAppCreateInfo;
    }
    
        // here for compatibility
    namespace engine {
        using tachyon::AppGLFW;
        using tachyon::AppCreateInfo;
        using tachyon::Monitor;
        using tachyon::VqApp;
    }
}

