////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Flags.hpp>
#include <yq-toolbox/basic/Guarded.hpp>
#include <yq-toolbox/basic/Ref.hpp>
#include <yq-toolbox/typedef/expected.hpp>
#include <yq-toolbox/typedef/rgba.hpp>

#include <yq-vulqan/config/vulqan.hpp>
#include <yq-vulqan/typedef/buffer.hpp>
#include <yq-vulqan/typedef/image.hpp>
#include <yq-vulqan/typedef/queue_tasker.hpp>
#include <yq-vulqan/typedef/sampler.hpp>
#include <yq-vulqan/typedef/shader.hpp>
#include <yq-vulqan/viewer/PresentMode.hpp>
#include <yq-vulqan/viz/ViCleanupManager.hpp>
#include <yq-vulqan/viz/ViQueueType.hpp>

#include <tbb/spin_rw_mutex.h>

#include <vulkan/vulkan_core.h>
#include <vk_mem_alloc.h>

#include <functional>
#include <atomic>
#include <memory>
#include <set>
#include <vector>

struct GLFWwindow;

namespace yq::tachyon {
    class Shader;
    
    struct ViewerCreateInfo;
    
    class ViQueueManager;
    
    template <typename V, typename A> class ViAssetManager;
    using ViBufferManager   = ViAssetManager<ViBuffer, Buffer>;
    using ViImageManager    = ViAssetManager<ViImage, Image>;
    using ViShaderManager   = ViAssetManager<ViShader, Shader>;
    using ViSamplerManager  = ViAssetManager<ViSampler, Sampler>;

    using ViImageManagerUPtr            = std::unique_ptr<ViImageManager>;
    using ViShaderManagerUPtr           = std::unique_ptr<ViShaderManager>;
    using ViBufferManagerUPtr           = std::unique_ptr<ViBufferManager>;
    using ViSamplerManagerUPtr          = std::unique_ptr<ViSamplerManager>;
    using ViQueueManagerPtr             = Ref<ViQueueManager>;
    using VkSurfaceCapabilitiesKHR_x    = Expect<VkSurfaceCapabilitiesKHR>;
    
    class VqApp;

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
        
        
        //! Memory allocator
        VmaAllocator                    allocator() const { return m_allocator; }

        //! Finds the buffer
        ViBufferCPtr                    buffer(uint64_t) const;
        ViBufferCPtr                    buffer_create(const Buffer&);
        void                            buffer_erase(uint64_t);
        void                            buffer_erase(const Buffer&);

        //! Buffer manager
        ViBufferManager*                buffer_manager() const;

        RGBA4F                          clear_color() const;

        VkQueue                         compute_queue(uint32_t i=0) const;
        uint32_t                        compute_queue_count() const;
        uint32_t                        compute_queue_family() const;
        ViQueueManager*                 compute_queue_manager() const;
        std::error_code                 compute_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            compute_queue_valid() const;

        //! Vulkan (logical) device
        VkDevice                        device() const { return m_device; }
        
        Expect<VkFormat>                find_depth_format() const;
        Expect<VkFormat>                find_supported_format(std::span<const VkFormat>, VkImageTiling, VkFormatFeatureFlags) const;
        Expect<VkFormat>                find_supported_format(std::initializer_list<VkFormat>, VkImageTiling, VkFormatFeatureFlags) const;

        //! Vulkan GPU (physical device)
        VkPhysicalDevice                gpu() const { return m_physical; }
        
            //! Returns the name of the GPU/physical device
        std::string_view                gpu_name() const;

            //! Returns the type of the GPU/physical device
        VkPhysicalDeviceType            gpu_type() const;

        VkQueue                         graphic_queue(uint32_t i=0) const;
        uint32_t                        graphic_queue_count() const;
        uint32_t                        graphic_queue_family() const;
        ViQueueManager*                 graphic_queue_manager() const;
        std::error_code                 graphic_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            graphic_queue_valid() const;

        ViImageCPtr                     image(uint64_t) const;
        ViImageCPtr                     image_create(const Image&);
        ViImageManager*                 image_manager() const;
        

        //! Vulkan instance
        VkInstance                      instance() const { return m_instance; }
        
        //! Vulkan logical device
        VkDevice                        logical() const { return m_device; }
        
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
        VkPhysicalDevice                physical() const { return m_physical; }

        VkQueue                         present_queue(uint32_t i=0) const;
        uint32_t                        present_queue_count() const;
        uint32_t                        present_queue_family() const;
        ViQueueManager*                 present_queue_manager() const;
        std::error_code                 present_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            present_queue_valid() const;

        std::error_code                 queue_task(ViQueueType, queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        
        ViSamplerCPtr                   sampler(uint64_t) const;
        ViSamplerCPtr                   sampler_create(const Sampler&);
        ViSamplerManager*               sampler_manager() const;

            //! Sets the background color
        void                            set_clear_color(const RGBA4F&);

        //! Finds the shader
        ViShaderCPtr                    shader(uint64_t) const;

        /*! Creates the shader
        
            This imports the shader onto the GPU device.  
            
            \note Once imported, this shader cannot be removed and will persist 
            to the end of the visualizer's lifespan.
        */
        ViShaderCPtr                    shader_create(const Shader&);

        //! Current shader manager (null if not initialized)
        ViShaderManager*                shader_manager() const;
        
        bool                            supports_surface(VkFormat) const;
        bool                            supports_present(PresentMode) const;

        //! Vulkan surface
        VkSurfaceKHR                    surface() const { return m_surface; }

        VkSurfaceCapabilitiesKHR_x      surface_capabilities() const;

        VkColorSpaceKHR                 surface_color_space() const;
        VkColorSpaceKHR                 surface_color_space(VkFormat) const;
        VkFormat                        surface_format() const;

        
        uint64_t                        tick() const { return m_tick; }

        VkQueue                         transfer_queue(uint32_t i=0) const;
        uint32_t                        transfer_queue_count() const;
        uint32_t                        transfer_queue_family() const;
        ViQueueManager*                 transfer_queue_manager() const;
        std::error_code                 transfer_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        
        //! IF valid, means there's an asynchronous DMA transfer queue
        bool                            transfer_queue_valid() const;

        VkQueue                         video_decode_queue(uint32_t i=0) const;
        uint32_t                        video_decode_queue_count() const;
        uint32_t                        video_decode_queue_family() const;
        ViQueueManager*                 video_decode_queue_manager() const;
        std::error_code                 video_decode_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            video_decode_queue_valid() const;

        VkQueue                         video_encode_queue(uint32_t i=0) const;
        uint32_t                        video_encode_queue_count() const;
        uint32_t                        video_encode_queue_family() const;
        ViQueueManager*                 video_encode_queue_manager() const;
        std::error_code                 video_encode_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            video_encode_queue_valid() const;

        //! Our window (underscore to demote)
        GLFWwindow*                     _window() const { return m_window; }



    protected:
        ViVisualizer();
        ~ViVisualizer();

        using mutex_t = tbb::spin_rw_mutex;

        mutable tbb::spin_rw_mutex          m_mutex;
        
        VmaAllocator                        m_allocator         = nullptr;
        VqApp*                              m_app               = nullptr;
        ViBufferManagerUPtr                 m_buffers;
        ViCleanupManager                    m_cleanup;                  // keep it one until performance bottlenecks
        Guarded<VkClearValue>               m_clearValue;
        ViQueueManager*                     m_computeQueue      = nullptr;
        VkDevice                            m_device            = nullptr;
        VkPhysicalDeviceFeatures            m_deviceFeatures;
        VkPhysicalDeviceProperties          m_deviceInfo;
        ViQueueManager*                     m_graphicsQueue     = nullptr;
        ViImageManagerUPtr                  m_images;
        VkInstance                          m_instance          = nullptr;
        VkPhysicalDeviceMemoryProperties    m_memoryInfo;
        struct {
            bool        enabled             = false;
            // KHR -- One greater than the maximum view index that can be used in a subpass.
            uint32_t    maxViewCount        = 0;
            // KHR -- maximum valid value of instance index allowed to be generated by a drawing command recorded within a subpass of a multiview render pass instance.
            uint32_t    maxInstanceIndex    = 0;
        }                                   m_multiview;
        VkPhysicalDevice                    m_physical          = nullptr;
        Guarded<PresentMode>                m_presentMode;
        std::set<PresentMode>               m_presentModes;
        ViQueueManager*                     m_presentQueue      = nullptr;
        std::vector<ViQueueManagerPtr>      m_queues;
        ViSamplerManagerUPtr                m_samplers;
        ViShaderManagerUPtr                 m_shaders;
        VkSurfaceKHR                        m_surface           = nullptr;
        VkColorSpaceKHR                     m_surfaceColorSpace;
        VkFormat                            m_surfaceFormat;
        std::vector<VkSurfaceFormatKHR>     m_surfaceFormats;
        ViQueueManager*                     m_transferQueue     = nullptr;
        ViQueueManager*                     m_videoDecQueue     = nullptr;
        ViQueueManager*                     m_videoEncQueue     = nullptr;
        GLFWwindow*                         m_window            = nullptr;
        
        std::atomic<uint64_t>               m_tick{0ULL};     // Always monotomically incrementing

        //Flags<F>            m_flags           = {};
        
        //! Transitory data needed during initialization
        struct InitData {
            const ViewerCreateInfo&                 viewer;
            std::vector<VkDeviceQueueCreateInfo>    queues;
            std::vector<const char*>                extensions;
            
            InitData(const ViewerCreateInfo& v) : viewer(v) {}
        };
        
        std::error_code     _0_app_window_initialize(GLFWwindow*);
        void                _0_app_window_kill();
        
        std::error_code     _1_gpu_select_initialize(InitData&);
        void                _1_gpu_select_kill();
        
        std::error_code     _2_surface_initialize(InitData&);
        void                _2_surface_kill();
        
        std::error_code     _3_queues_create(InitData&);
        void                _3_queues_fetch();   // post device creation
        void                _3_queues_kill();
        
        std::error_code     _4_device_init(InitData&);
        void                _4_device_kill();
        
        std::error_code     _5_allocator_init(InitData& iData);
        void                _5_allocator_kill();
        
        std::error_code     _6_manager_init();
        void                _6_manager_kill();
    };
}
