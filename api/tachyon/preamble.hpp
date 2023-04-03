////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/preamble.hpp>
#include <basic/Logging.hpp>
#include <variant>

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

        class Shader;
        class Texture;

        using ShaderSpec        = std::variant<std::monostate, std::string, Ref<const Shader>>;

        struct  Joystick;
        class   Monitor;
        class   Pipeline;
        class   PipelineBuilder;
        struct  PipelineConfig;
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
        using tachyon::PipelineBuilder;
        using tachyon::PipelineConfig;
        using tachyon::ViewerCreateInfo;
        using tachyon::VqApp;
        using tachyon::VqException;
        using tachyon::Window;
        using tachyon::Shader;
        using tachyon::ShaderSpec;
    }
}

