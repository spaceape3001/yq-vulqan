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
        struct  AppCreateInfo;
        class   AppGLFW;
        class   Asset;
        class   AssetCache;
        class   AssetCompiler;
        class   AssetCompilerInfo;
        class   AssetInfo;
        class   AssetLoader;
        class   AssetLoaderInfo;

        struct  Joystick;
        class   Monitor;
        struct  ResultCC;
        struct  VideoMode;
        class   Visualizer;
        class   Viewer;
        struct  ViewerCreateInfo;
        class   VqApp;
        class   VqException;
        class   Window;
    }
    
        // here for compatibility
    namespace engine {
        using tachyon::AppGLFW;
        using tachyon::AppCreateInfo;
        using tachyon::Asset;
        using tachyon::AssetCache;
        using tachyon::AssetCompiler;
        using tachyon::AssetCompilerInfo;
        using tachyon::AssetInfo;
        using tachyon::AssetLoader;
        using tachyon::AssetLoaderInfo;
        using tachyon::Monitor;
        using tachyon::ResultCC;
        using tachyon::ViewerCreateInfo;
        using tachyon::VqApp;
        using tachyon::VqException;
        using tachyon::Window;
    }
}

