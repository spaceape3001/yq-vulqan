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
#include <yq-vulqan/viewer/PresentMode.hpp>
#include <yq-vulqan/viz/ViCleanupManager.hpp>

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
    class Buffer;
    class Shader;
    
    struct ViewerCreateInfo;
    
    struct ViBuffer;
    struct ViShader;
    
    class ViBufferManager;
    class ViShaderManager;
    class ViQueueManager;
    
    using ViShaderManagerUPtr           = std::unique_ptr<ViShaderManager>;
    using ViBufferManagerUPtr           = std::unique_ptr<ViBufferManager> ;
    using ViQueueManagerPtr             = Ref<ViQueueManager>;
    using VkSurfaceCapabilitiesKHR_x    = Expect<VkSurfaceCapabilitiesKHR>;
    
    class VqApp;
    
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
        Expect<ViBuffer>                buffer(uint64_t) const;
        Expect<ViBuffer>                buffer_create(const Buffer&);
        void                            buffer_erase(uint64_t);
        void                            buffer_erase(const Buffer&);

        //! Buffer manager
        ViBufferManager*                buffer_manager() const;

        RGBA4F                          clear_color() const;

        VkQueue                         compute_queue(uint32_t i=0) const;
        uint32_t                        compute_queue_count() const;
        uint32_t                        compute_queue_family() const;
        ViQueueManager*                 compute_queue_manager() const;
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
        bool                            graphic_queue_valid() const;

        //! Vulkan instance
        VkInstance                      instance() const { return m_instance; }
        
        //! Vulkan logical device
        VkDevice                        logical() const { return m_device; }
        
        uint32_t                        max_memory_allocation_count() const;
        uint32_t                        max_push_constants_size() const;
        uint32_t                        max_viewports() const;

        //! Vulkan physical device (gpu)
        VkPhysicalDevice                physical() const { return m_physical; }

        VkQueue                         present_queue(uint32_t i=0) const;
        uint32_t                        present_queue_count() const;
        uint32_t                        present_queue_family() const;
        ViQueueManager*                 present_queue_manager() const;
        bool                            present_queue_valid() const;
        
            //! Sets the background color
        void                            set_clear_color(const RGBA4F&);

        //! Finds the shader
        Expect<ViShader>                shader(uint64_t) const;

        /*! Creates the shader
        
            This imports the shader onto the GPU device.  
            
            \note Once imported, this shader cannot be removed and will persist 
            to the end of the visualizer's lifespan.
        */
        Expect<ViShader>                shader_create(const Shader&);

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
        
        //! IF valid, means there's an asynchronous DMA transfer queue
        bool                            transfer_queue_valid() const;

        VkQueue                         video_decode_queue(uint32_t i=0) const;
        uint32_t                        video_decode_queue_count() const;
        uint32_t                        video_decode_queue_family() const;
        ViQueueManager*                 video_decode_queue_manager() const;
        bool                            video_decode_queue_valid() const;

        VkQueue                         video_encode_queue(uint32_t i=0) const;
        uint32_t                        video_encode_queue_count() const;
        uint32_t                        video_encode_queue_family() const;
        ViQueueManager*                 video_encode_queue_manager() const;
        bool                            video_encode_queue_valid() const;

        //! Our window (underscore to demote)
        GLFWwindow*                     _window() const { return m_window; }



    protected:
        ViVisualizer();
        ~ViVisualizer();

        using mutex_t = tbb::spin_rw_mutex;

        mutable tbb::spin_rw_mutex          m_mutex;
        
        VmaAllocator                        m_allocator   = nullptr;
        VqApp*                              m_app         = nullptr;
        ViBufferManagerUPtr                 m_buffers;
        ViCleanupManager                    m_cleanup;                  // keep it one until performance bottlenecks
        Guarded<VkClearValue>               m_clearValue;
        ViQueueManager*                     m_compute     = nullptr;
        VkDevice                            m_device      = nullptr;
        VkPhysicalDeviceFeatures            m_deviceFeatures;
        VkPhysicalDeviceProperties          m_deviceInfo;
        ViQueueManager*                     m_graphics    = nullptr;
        VkInstance                          m_instance    = nullptr;
        VkPhysicalDeviceMemoryProperties    m_memoryInfo;
        VkPhysicalDevice                    m_physical    = nullptr;
        ViQueueManager*                     m_present     = nullptr;
        Guarded<PresentMode>                m_presentMode;
        std::set<PresentMode>               m_presentModes;
        std::vector<ViQueueManagerPtr>      m_queues;
        ViShaderManagerUPtr                 m_shaders;
        VkSurfaceKHR                        m_surface     = nullptr;
        VkColorSpaceKHR                     m_surfaceColorSpace;
        VkFormat                            m_surfaceFormat;
        std::vector<VkSurfaceFormatKHR>     m_surfaceFormats;
        ViQueueManager*                     m_transfer    = nullptr;
        ViQueueManager*                     m_videoDec    = nullptr;
        ViQueueManager*                     m_videoEnc    = nullptr;
        GLFWwindow*                         m_window      = nullptr;
        
        std::atomic<uint64_t>               m_tick{0ULL};     // Always monotomically incrementing

        //Flags<F>            m_flags           = {};
        
        std::error_code     _0_app_window_initialize(GLFWwindow*);
        void                _0_app_window_kill();
        
        std::error_code     _1_gpu_select_initialize(const ViewerCreateInfo&);
        void                _1_gpu_select_kill();
        
        std::error_code     _2_surface_initialize(const ViewerCreateInfo&);
        void                _2_surface_kill();
        
        std::error_code     _3_queues_create(std::vector<VkDeviceQueueCreateInfo>&, const ViewerCreateInfo&);
        void                _3_queues_fetch();   // post device creation
        void                _3_queues_kill();
    };
}
