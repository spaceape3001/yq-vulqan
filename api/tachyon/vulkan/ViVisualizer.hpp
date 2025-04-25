////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Cleanup.hpp>
#include <yq/core/Flags.hpp>
#include <yq/core/Guarded.hpp>
#include <yq/core/Ref.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/typedef/expected.hpp>
#include <yq/typedef/rgba.hpp>

#include <yt/config/vulqan.hpp>
#include <yt/keywords.hpp>
#include <tachyon/gfx/PresentMode.hpp>
#include <tachyon/typedef/raster.hpp>
#include <tachyon/typedef/vi_buffer.hpp>
#include <tachyon/typedef/vi_device.hpp>
#include <tachyon/typedef/vi_image.hpp>
#include <tachyon/typedef/vi_queue_id.hpp>
#include <tachyon/typedef/vi_queue_tasker.hpp>
#include <tachyon/typedef/vi_pipeline.hpp>
#include <tachyon/typedef/vi_pipeline_layout.hpp>
#include <tachyon/typedef/vi_pipeline_manager.hpp>
#include <tachyon/typedef/vi_render_pass.hpp>
#include <tachyon/typedef/vi_sampler.hpp>
#include <tachyon/typedef/vi_shader.hpp>
#include <tachyon/typedef/vi_surface.hpp>
#include <tachyon/typedef/vi_swapchain.hpp>
#include <tachyon/typedef/vi_texture.hpp>
#include <tachyon/vulkan/ViQueueType.hpp>
#include <tachyon/vulkan/vulqan.hpp>

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
    
    struct VizTaskerOptions {
        uint64_t        timeout = DEFAULT_WAIT_TIMEOUT;
        uint32_t        queue   = 0;
    };
    
    
    /*! \brief the Physical vulkan device adapter
        
        This is about transferreing resources to/from the device, 
        making pipelines, etc.  It's expected to have ONE visualizer
        per viewer/logical vulkan device.
    *//*
        Note, if this needs to be shared, we'll make it ref-counted.
        Also, thread-safety is to be done *outside* this class (performance)
    *//*
        NOTICE!!!   This class will be renamed after the absorption is complete
    */
    class ViVisualizer {
    public:
        //enum class F : uint8_t {
        //};

        struct DrawFunctions {
            std::function<void(ViContext&)>     prerecord;
            std::function<void(ViContext&)>     record;
        };
        
        struct CreateData;
        
        
        //! Memory allocator
        VmaAllocator                    allocator() const;

        ViBufferCPtr                    buffer(uint64_t) const;
        ViBufferCPtr                    buffer_create(const Buffer&);
        void                            buffer_erase(uint64_t);
        void                            buffer_erase(const Buffer&);
        
        void                            cleanup(cleanup_fn&&);
        void                            cleanup(sweep_k);

        RGBA4F                          clear_color() const;

        VkQueue                         compute_queue() const;
        ViQueueFamilyID                 compute_queue_family() const { return m_computeQueue.family; }
        ViQueueID                       compute_queue_id() const { return m_computeQueue; }
        std::error_code                 compute_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            compute_queue_valid() const;

        virtual VkDescriptorPool        descriptor_pool() const = 0;

        //! Vulkan (logical) device
        VkDevice                        device() const;
        
        ViDevice&                       device(ref_k) { return *m_device; }  // temporary hack until we get everybody over....
        ViDevice*                       device(ptr_k) { return m_device.ptr(); }  // temporary hack until we get everybody over....
        
        Expect<VkFormat>                find_depth_format() const;
        Expect<VkFormat>                find_supported_format(std::span<const VkFormat>, VkImageTiling, VkFormatFeatureFlags) const;
        Expect<VkFormat>                find_supported_format(std::initializer_list<VkFormat>, VkImageTiling, VkFormatFeatureFlags) const;

        Size2I                          framebuffer_size() const { return m_frameBufferSize; }

        //! Vulkan GPU (physical device)
        VkPhysicalDevice                gpu() const;
        
            //! Returns the name of the GPU/physical device
        std::string_view                gpu_name() const;

            //! Returns the type of the GPU/physical device
        VkPhysicalDeviceType            gpu_type() const;

        VkQueue                         graphic_queue() const;
        ViQueueFamilyID                 graphic_queue_family() const { return m_graphicsQueue.family; }
        ViQueueID                       graphic_queue_id() const { return m_graphicsQueue; }
        std::error_code                 graphic_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            graphic_queue_valid() const;

        ViImageCPtr                     image(uint64_t) const;
        ViImageCPtr                     image_create(const Raster&);
        Expect<RasterPtr>               image_export(VkImage, const VkExtent2D&, VkFormat fmt = VK_FORMAT_R8G8B8A8_SRGB);
        Expect<RasterPtr>               image_export(VkImage, const VkExtent3D&, VkFormat fmt = VK_FORMAT_R8G8B8A8_SRGB);
        void                            image_erase(uint64_t);
        void                            image_erase(const Raster&);
        
        //! Vulkan instance
        static VkInstance               instance();
        
        //! Vulkan logical device
        VkDevice                        logical() const;

        uint32_t                        max_memory_allocation_count() const;
        uint32_t                        max_push_constants_size() const;
        float                           max_sampler_anisotropy() const;
        uint32_t                        max_viewports() const;

        //! TRUE if multiple views of the render-pass is enabled
        bool                            multiview_enabled() const;
        
        /*! \brief Maximum index value
        
            KHR's description:
            maxMultiviewInstanceIndex is the maximum valid value of instance index allowed to be generated by a 
            drawing command recorded within a subpass of a multiview render pass instance.            
        */
        uint32_t                        multiview_max_instance_index() const;
        
        /*! Maximumum number of views
        
            KHR's description:
            maxMultiviewViewCount is one greater than the maximum view index that can be used in a subpass.
        */
        uint32_t                        multiview_max_view_count() const;

        //! Vulkan physical device (gpu)
        VkPhysicalDevice                physical() const;
        
        ViPipelineCPtr                  pipeline(uint64_t) const;
        ViPipelineCPtr                  pipeline_create(const Pipeline*);
        void                            pipeline_erase(uint64_t);
        void                            pipeline_erase(const Pipeline*);
        ViPipelineManager*              pipeline_manager() const;
        
        ViPipelineLayoutCPtr            pipeline_layout(uint64_t) const;
        ViPipelineLayoutCPtr            pipeline_layout_create(const Pipeline*);
        void                            pipeline_layout_erase(uint64_t);
        void                            pipeline_layout_erase(const Pipeline*);

        PresentMode                     present_mode() const;
        const std::set<PresentMode>&    present_modes_available() const;

        VkQueue                         present_queue() const;
        ViQueueFamilyID                 present_queue_family() const { return m_presentQueue.family; }
        ViQueueID                       present_queue_id() const { return m_presentQueue; }
        std::error_code                 present_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            present_queue_valid() const;

        std::error_code                 queue_task(ViQueueType, queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());

        VkRenderPass                    render_pass() const;
        
        ViSamplerCPtr                   sampler(uint64_t) const;
        ViSamplerCPtr                   sampler_create(const Sampler&);
        void                            sampler_erase(uint64_t);
        void                            sampler_erase(const Sampler&);

            //! Sets the background color
        void                            set_clear_color(const RGBA4F&);

        void                            set_framebuffer_size(const Size2I&);

        void                            set_present_mode(PresentMode);

        //! Finds the shader
        ViShaderCPtr                    shader(uint64_t) const;

        /*! Creates the shader
        
            This imports the shader onto the GPU device.  
            
            \note Once imported, this shader cannot be removed and will persist 
            to the end of the visualizer's lifespan.
        */
        ViShaderCPtr                    shader_create(const Shader&);

        void                            shader_erase(uint64_t);
        void                            shader_erase(const Shader&);
        
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

        ViTextureCPtr                   texture(uint64_t) const;
        ViTextureCPtr                   texture_create(const Texture&);
        void                            texture_erase(uint64_t);
        void                            texture_erase(const Texture&);
        
        uint64_t                        tick() const { return m_tick; }

        VkQueue                         transfer_queue() const;
        uint32_t                        transfer_queue_count() const;
        ViQueueFamilyID                 transfer_queue_family() const;
        ViQueueID                       transfer_queue_id() const { return m_transferQueue; }
        std::error_code                 transfer_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        
        //! IF valid, means there's an asynchronous DMA transfer queue
        bool                            transfer_queue_valid() const;

        void                            trigger_rebuild();

        VkQueue                         video_decode_queue() const;
        ViQueueFamilyID                 video_decode_queue_family() const;
        ViQueueID                       video_decode_queue_id() const { return m_videoDecQueue; }
        std::error_code                 video_decode_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            video_decode_queue_valid() const;

        VkQueue                         video_encode_queue() const;
        ViQueueFamilyID                 video_encode_queue_family() const;
        ViQueueID                       video_encode_queue_id() const { return m_videoEncQueue; }
        std::error_code                 video_encode_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            video_encode_queue_valid() const;

        std::error_code                 wait_idle();
        

    protected:
        ViVisualizer(const CreateData&);
        ~ViVisualizer();
        
        enum class X {
            Compute,
            Transfer,
            VideoEnc,
            VideoDec
        };

        using mutex_t = tbb::spin_rw_mutex;

        mutable tbb::spin_rw_mutex          m_mutex;
        
        Guarded<VkClearValue>               m_clearValue;
        ViQueueID                           m_computeQueue;
        ViDevicePtr                         m_device;
        //VkPhysicalDeviceFeatures            m_deviceFeatures;
        //VkPhysicalDeviceProperties          m_deviceInfo;
        Flags<X>                            m_flags;
        Size2I                              m_frameBufferSize   = {}; // For when we divorce the visualizer from the main thread
        uint32_t                            m_frameImageIndex   = 0;
        ViQueueID                           m_graphicsQueue;
        ViPipelineManagerUPtr               m_pipelines;        // temporary until relocated
        Guarded<PresentMode>                m_presentMode;
        std::set<PresentMode>               m_presentModes;
        ViQueueID                           m_presentQueue;
        std::atomic<bool>                   m_rebuildSwap       = { false };
        ViRenderPassCPtr                    m_renderPass;
        ViSurfacePtr                        m_surface;
        VkColorSpaceKHR                     m_surfaceColorSpace;
        VkFormat                            m_surfaceFormat;
        std::vector<VkSurfaceFormatKHR>     m_surfaceFormats;
        ViSwapchainCPtr                     m_swapchain;
        ViQueueID                           m_transferQueue;
        ViQueueID                           m_videoDecQueue;
        ViQueueID                           m_videoEncQueue;
        
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
