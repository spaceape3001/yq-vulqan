////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Cleanup.hpp>
#include <yq/core/Flags.hpp>
#include <yq/core/Ref.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/typedef/expected.hpp>
#include <yq/typedef/rgba.hpp>

#include <yq/tachyon/config/vulqan.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/pipeline/PresentMode.hpp>
#include <yq/tachyon/typedef/raster.hpp>
#include <yq/tachyon/typedef/vi_buffer.hpp>
#include <yq/tachyon/typedef/vi_device.hpp>
#include <yq/tachyon/typedef/vi_image.hpp>
#include <yq/tachyon/typedef/vi_queue_id.hpp>
#include <yq/tachyon/typedef/vi_queue_tasker.hpp>
#include <yq/tachyon/typedef/vi_pipeline.hpp>
#include <yq/tachyon/typedef/vi_pipeline_layout.hpp>
#include <yq/tachyon/typedef/vi_pipeline_manager.hpp>
#include <yq/tachyon/typedef/vi_render_pass.hpp>
#include <yq/tachyon/typedef/vi_sampler.hpp>
#include <yq/tachyon/typedef/vi_shader.hpp>
#include <yq/tachyon/typedef/vi_surface.hpp>
#include <yq/tachyon/typedef/vi_swapchain.hpp>
#include <yq/tachyon/typedef/vi_texture.hpp>
#include <yq/tachyon/vulkan/ViQueueType.hpp>
#include <yq/tachyon/vulkan/VizBase.hpp>
#include <yq/tachyon/vulkan/vulqan.hpp>

#include <tbb/spin_rw_mutex.h>

#include <vk_mem_alloc.h>

#include <functional>
#include <atomic>
#include <memory>
#include <set>
#include <vector>

struct GLFWwindow;

namespace yq::tachyon {
    struct ViewerCreateInfo;
    class ViQueueManager;
    struct ViContext;
    class Buffer;
    class Sampler;
    class Shader;
    
    using ViQueueManagerPtr             = Ref<ViQueueManager>;
    using VkSurfaceCapabilitiesKHR_x    = Expect<VkSurfaceCapabilitiesKHR>;
    
    
    /*! \brief the Physical vulkan device adapter
        
        This is about transferreing resources to/from the device, 
        making pipelines, etc.  It's expected to have ONE visualizer
        per viewer/logical vulkan device.
    *//*
        Note, if this needs to be shared, we'll make it ref-counted.
        Also, thread-safety is to be done *outside* this class (performance)
    *//*
        NOTICE!!!   This class will be renamed after the absorption is complete (Well, maybe on the rename)
    */
    class ViVisualizer : public VizBase {
    public:
        //enum class F : uint8_t {
        //};

        struct RenderTarget {
            VkRenderPass        render_pass = nullptr;
            VkFramebuffer       framebuffer = nullptr;
            VkViewport          viewport{};
            VkClearValue        clear{};
        };
        
        struct CreateData;



        

        Size2I                          framebuffer_size() const { return m_frameBufferSize; }


        
        ViPipelineCPtr                  pipeline(uint64_t) const;
        ViPipelineCPtr                  pipeline_create(const Pipeline*);
        void                            pipeline_erase(uint64_t);
        void                            pipeline_erase(const Pipeline*);
        ViPipelineManager*              pipeline_manager() const;
     
        PresentMode                     present_mode() const;
        const std::set<PresentMode>&    present_modes_available() const;


        VkRenderPass                    render_pass() const;

        void                            set_framebuffer_size(const Size2I&);

        void                            set_present_mode(PresentMode);
        
        bool                            supports_surface(VkFormat) const;
        bool                            supports_present(PresentMode) const;

        //! Vulkan surface
        VkSurfaceKHR                    surface() const;

        VkSurfaceCapabilitiesKHR_x      surface_capabilities() const;

        VkColorSpaceKHR                 surface_color_space() const;
        VkColorSpaceKHR                 surface_color_space(VkFormat) const;
        VkFormat                        surface_format() const;

        VkSwapchainKHR                  swapchain() const;
        VkRect2D                        swapchain_def_scissor() const;
        VkViewport                      swapchain_def_viewport() const;
        uint32_t                        swapchain_height() const;
        uint32_t                        swapchain_image_count() const;
        uint32_t                        swapchain_min_image_count() const;
        uint32_t                        swapchain_width() const;
        
        uint64_t                        tick() const { return m_tick; }

        void                            trigger_rebuild();

        

    protected:
        ViVisualizer(const CreateData&);
        ~ViVisualizer();

        using mutex_t = tbb::spin_rw_mutex;

        mutable tbb::spin_rw_mutex          m_mutex;
        
        //ViDevicePtr                         m_device;
        //VkPhysicalDeviceFeatures            m_deviceFeatures;
        //VkPhysicalDeviceProperties          m_deviceInfo;
        Size2I                              m_frameBufferSize   = {}; // For when we divorce the visualizer from the main thread
        uint32_t                            m_frameImageIndex   = 0;
        ViPipelineManagerUPtr               m_pipelines;        // temporary until relocated
        Guarded<PresentMode>                m_presentMode;
        std::set<PresentMode>               m_presentModes;
        std::atomic<bool>                   m_rebuildSwap       = { false };
        ViRenderPassCPtr                    m_renderPass;
        ViSurfacePtr                        m_surface;
        VkColorSpaceKHR                     m_surfaceColorSpace;
        VkFormat                            m_surfaceFormat;
        std::vector<VkSurfaceFormatKHR>     m_surfaceFormats;
        ViSwapchainCPtr                     m_swapchain;
        
        std::atomic<uint64_t>               m_tick{0ULL};     // Always monotomically incrementing

            // Temporary until moved to the frames

        //Flags<F>            m_flags           = {};
        
        std::error_code     _6_manager_init();
        void                _6_manager_kill();
        
        std::error_code     _7_render_pass_create();
        void                _7_render_pass_kill();
        
        std::error_code     _8_swapchain_create();
        void                _8_swapchain_kill();

        std::error_code     _9_pipeline_manager_create();
        void                _9_pipeline_manager_kill();

        /*! Rebuilds the swapchain
        */
        void                _rebuild_swapchain();
        
    private:
        std::error_code     _init(const CreateData&);
        void                _kill();
    };
}
