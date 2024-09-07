////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once


#include <yq-toolbox/basic/Logging.hpp>
#include <variant>

struct GLFWmonitor;
struct GLFWvidmode;
struct GLFWwindow;

namespace yq {
    template <size_t N> class BasicBuffer;
    template <typename> class Ref;
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
    class   Application;
    class   Event;
    class   Pipeline;
    //class   LegacyPipelineBuilder;
    struct  Perspective;
    //using   PipelineBuilder = LegacyPipelineBuilder;
    struct  PipelineConfig;
    struct  Scene;
    class   Rendered;
    struct  Texture;
    struct  ViContext;
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

    
    using TextureCPtr   = Ref<const Texture>;
    using PipelineCPtr  = Ref<const Pipeline>;
    using RenderedPtr   = Ref<Rendered>;
    using RenderedCPtr  = Ref<const Rendered>;

    using PushBuffer    = BasicBuffer<MAX_PUSH>;

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
        using tachyon::ViewerCreateInfo;
        using tachyon::VqException;
        using tachyon::Window;
    }
    #endif

namespace yq {
    
    //using tachyon::Camera;
    using tachyon::Texture;
    //using tachyon::Shader;
    using tachyon::Widget;
}

