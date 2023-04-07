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
    template <size_t N> class BasicBuffer;
    
    namespace asset {
    }

    //! Namespace for our vulkan code... deliberately mispelled with a "Q"
    namespace vulqan {
    }
    
    namespace engine {
        class Viewer;
    }
    
    namespace tachyon {
        static constexpr const size_t   MAX_PUSH                = 256;
        static constexpr const size_t   MAX_FRAMES_IN_FLIGHT    = 2;
        static constexpr const uint32_t MIN_DESCRIPTOR_COUNT    = 1024;

        struct  AppCreateInfo;
        class   AppGLFW;
        class   Application;
        class   Asset;
        class   AssetCache;
        class   AssetInfo;
        class   AssetFactory;
        class   Buffer;
        class   Camera;
        struct  CameraParams;
        struct  Joystick;
        class   Monitor;
        class   Pipeline;
        class   PipelineBuilder;
        struct  PipelineConfig;
        class   Shader;
        class   Texture;
        struct  ViContext;
        struct  VideoMode;
        class   Visualizer;
        class   Viewer;
        struct  ViewerCreateInfo;
        class   VqApp;
        class   VqException;
        class   VqRecord;
        class   Widget;
        class   Window;

        template <typename> class TypedAssetFactory;
        
        using PushBuffer    = BasicBuffer<MAX_PUSH>;
        using ShaderSpec    = std::variant<std::monostate, std::string, Ref<const Shader>>;
    }
    
        // here for compatibility
    namespace engine {
        static constexpr const size_t   MAX_PUSH                = tachyon::MAX_PUSH;
        static constexpr const size_t   MAX_FRAMES_IN_FLIGHT    = tachyon::MAX_FRAMES_IN_FLIGHT;
        static constexpr const uint32_t MIN_DESCRIPTOR_COUNT    = tachyon::MIN_DESCRIPTOR_COUNT;


        using tachyon::AppGLFW;
        using tachyon::AppCreateInfo;
        //using tachyon::Asset;
        //using tachyon::AssetCache;
        //using tachyon::AssetInfo;
        using tachyon::Monitor;
        using tachyon::PipelineBuilder;
        using tachyon::PipelineConfig;
        using tachyon::ShaderSpec;
        using tachyon::ViewerCreateInfo;
        using tachyon::VqApp;
        using tachyon::VqException;
        using tachyon::Window;
    }
    
    using tachyon::Camera;
    using tachyon::Pipeline;
    using tachyon::Texture;
    using tachyon::Shader;
}

