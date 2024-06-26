////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/preamble.hpp>
#include <0/basic/Logging.hpp>
#include <variant>

struct GLFWmonitor;
struct GLFWvidmode;
struct GLFWwindow;

namespace yq {
    template <size_t N> class BasicBuffer;
}

    //namespace asset {
    //}

    //! Namespace for our vulkan code... deliberately mispelled with a "Q"
    //namespace vulqan {
    //}
    
    //namespace engine {
        //class Viewer;
    //}

namespace yq::tachyon {
    static constexpr const size_t   MAX_PUSH                = 256;
    //static constexpr const size_t   MAX_FRAMES_IN_FLIGHT    = 2;
    static constexpr const uint32_t MIN_DESCRIPTOR_COUNT    = 1024;
    
    //namespace imgui {}

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
    class   Event;
    class   Image;
    struct  ImageInfo;
    struct  ImageViewInfo;
    struct  Joystick;
    class   Memory;
    class   Monitor;
    class   Pipeline;
    //class   LegacyPipelineBuilder;
    struct  Perspective;
    //using   PipelineBuilder = LegacyPipelineBuilder;
    struct  PipelineConfig;
    struct  Scene;
    struct  SamplerInfo;
    class   Shader;
    class   Rendered;
    struct  Texture;
    struct  ViContext;
    struct  VideoMode;
    class   Visualizer;
    class   Viewer;
    struct  ViewerCreateInfo;
    //struct  ViPipeline;
    struct  ViRendered;
    class   VqApp;
    class   VqException;
    class   VqRecord;
    class   Widget;
    class   Window;
    
    using ViThing = ViRendered;


    template <typename> class TypedAssetFactory;
    
    using BufferCPtr    = Ref<const Buffer>;
    using CameraCPtr    = Ref<const Camera>;
    using TextureCPtr   = Ref<const Texture>;
    using ShaderCPtr    = Ref<const Shader>;
    using PipelineCPtr  = Ref<const Pipeline>;
    using RenderedPtr   = Ref<Rendered>;
    using RenderedCPtr  = Ref<const Rendered>;

    using PushBuffer    = BasicBuffer<MAX_PUSH>;
    using ShaderSpec    = std::variant<std::monostate, std::string, ShaderCPtr>;

    using ViQueueSpec   = std::variant<std::monostate, bool, uint32_t, std::vector<float>>;
}
    
    #if 0
        // here for compatibility
    namespace engine {
        static constexpr const size_t   MAX_PUSH                = tachyon::MAX_PUSH;
        static constexpr const size_t   MAX_FRAMES_IN_FLIGHT    = tachyon::MAX_FRAMES_IN_FLIGHT;
        static constexpr const uint32_t MIN_DESCRIPTOR_COUNT    = tachyon::MIN_DESCRIPTOR_COUNT;


        using tachyon::AppCreateInfo;
        //using tachyon::Monitor;
        using tachyon::PipelineBuilder;
        using tachyon::PipelineConfig;
        using tachyon::ShaderSpec;
        using tachyon::ViewerCreateInfo;
        using tachyon::VqException;
        using tachyon::Window;
    }
    #endif

namespace yq {
    
    using tachyon::Camera;
    using tachyon::Texture;
    using tachyon::Shader;
    using tachyon::Widget;
}

