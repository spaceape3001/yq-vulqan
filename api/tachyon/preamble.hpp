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
        class   AssetInfo;
        class   AssetFactory;

        template <typename> class TypedAssetFactory;
        template <typename> class TypedAssetLoader;

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
        using tachyon::AssetInfo;
        using tachyon::Monitor;
        using tachyon::ResultCC;
        using tachyon::ViewerCreateInfo;
        using tachyon::VqApp;
        using tachyon::VqException;
        using tachyon::Window;
    }
}

