////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>

#include <basic/Guarded.hpp>
#include <math/preamble.hpp>
#include <tachyon/enum/PresentMode.hpp>
#include <tachyon/enum/Tristate.hpp>

#include <atomic>
#include <functional>
#include <map>
#include <set>
#include <string_view>
#include <unordered_map>
#include <vector>

#include <vk_mem_alloc.h>
#include <vulkan/vulkan_core.h>
#include <tbb/spin_rw_mutex.h>

namespace yq::tachyon {

    struct ViBuffer;
    struct ViShader;
    struct ViImage;
    struct ViQueues;
    struct ViRender;
    struct ViSwapchain;
    struct ViPipeline;
    struct ViFrame;
    struct ViTexture;
    


    class Memory;

    struct ViBuffer {
        VkBuffer                buffer      = nullptr;
        VmaAllocation           allocation  = nullptr;
    };

    
    //!  Represents an image (likely from file) that has been pushed to the GPU
    struct ViImage {
        VmaAllocation           allocation  = nullptr;
        VkImage                 image       = nullptr;
    };

    struct ViQueues {
        std::vector<VkQueue>    queues;
        uint32_t                family   = UINT32_MAX;
        
        void    set(VkDevice, uint32_t cnt);
        VkQueue operator[](uint32_t i) const;
        bool valid() const { return family != UINT32_MAX; }
    };
    
    struct ViSwapchain {
        VkSwapchainKHR              swapchain       = nullptr;
        VkExtent2D                  extents         = {};
        uint32_t                    minImageCount   = 0;
        uint32_t                    imageCount      = 0;
        std::vector<VkImage>        images;
        std::vector<VkImageView>    imageViews;
        std::vector<VkFramebuffer>  frameBuffers;
        VkSurfaceCapabilitiesKHR    capabilities;
        
        VkRect2D    def_scissor() const;
        VkViewport  def_viewport() const;
        uint32_t    width() const;
        uint32_t    height() const;
    };
    
        // eventually multithread...
    struct ViThread {
        VkDescriptorPool        descriptors         = nullptr;
        VkCommandPool           graphic             = nullptr;
        VkCommandPool           compute             = nullptr;
    };
    
    struct ViTexture  {
        VkImageView             view        = nullptr;
        VkSampler               sampler     = nullptr;
    };
    
    struct ViUpload {
        VkFence                 fence           = nullptr;
        VkCommandPool           pool            = nullptr;
        VkCommandBuffer         commandBuffer   = nullptr;
        VkQueue                 queue           = nullptr;
    };

        //  and so we can be more efficient in rendering
    struct ViFrame {
        VkCommandBuffer         commandBuffer   = nullptr;
        VkSemaphore             imageAvailable  = nullptr;
        VkSemaphore             renderFinished  = nullptr;
        VkFence                 fence           = nullptr;
    };
    
    //template <typename T>
    //struct ViMap {
        //std::map<uint64_t, T>       map;
        //mutable tbb::spin_rw_mutex  mutex;
        
    //};
    


    /*! \brief the Physical vulkan device adapter
        
        This is about transferreing resources to/from the device, 
        making pipelines, etc.  It's expected to have ONE visualizer
        per viewer/logical vulkan device.
    *//*
        Note, if this needs to be shared, we'll make it ref-counted.
        Also, thread-safety is to be done *outside* this class (performance)
    */
    class Visualizer  {
    public:
    
    
        
        enum class Queue : uint8_t {
            Graphic,
            Present,
            Compute,
            VideoEnable,
            VideoDisable,
            COUNT
        };
        
        using DrawFunction              = std::function<void(ViContext&)>;
    
    
        //  since this is "stolen", demoted
        GLFWwindow*                     _window() const { return m_window; }
        VmaAllocator                    allocator() const { return m_allocator; }
        VkDevice                        device() const { return m_device; }
        VkDevice                        logical() const { return m_device; }
        VkInstance                      instance() const { return m_instance; }
        VkPhysicalDevice                physical() const { return m_physical; }

        //! Finds the buffer
        //! \note Reference is only good to the next create()
        const ViBuffer&                 buffer(uint64_t) const;

        RGBA4F                          clear_color() const;

        VkCommandBuffer                 command_buffer() const;
        VkCommandPool                   command_pool() const;

        VkQueue                         compute_queue(uint32_t i=0) const;
        uint32_t                        compute_queue_count() const;
        uint32_t                        compute_queue_family() const;
        bool                            compute_queue_valid() const;

        //! Creates the buffer
        //! \note Reference is only good to the next create()
        const ViBuffer&                 create(const Buffer&);

        /*! Creates the shader
        
            This imports the shader onto the GPU device.  
            
            \note Once imported, this shader cannot be removed and will persist 
            to the end of the visualizer's lifespan.
        */
        Expect<ViShader>                create(const Shader&);

        Expect<ViImage>                 create(const Image&);  // temporary name until texture's altered

        //! Creates the pipeline
        //! \note Reference is only good to the next create()
        const ViPipeline&               create(const Pipeline&);

        const ViThing&                  create(const Rendered&, const Pipeline&);
        
        Expect<ViTexture>               create(const Texture&);
        

        ViFrame&                        current_frame();
        const ViFrame&                  current_frame() const;
        
        VkDescriptorPool                descriptor_pool() const;

        /*! \brief "Draws" 
        
            \note Nothing stops recursion... DON'T
        */
        std::error_code                 draw(ViContext&, DrawFunction use={});
        
        void                            draw_scene(ViContext&, const Scene&, const Perspective&);
        
        //! Draw a specific item, matrix assumed correct
        void                            draw_object(ViContext&, const Rendered&, Tristate wireframe=Tristate::INHERIT);

        //! Draw a specific item, matrix assumed correct, with given pipeline
        void                            draw_object(ViContext&, const Rendered&, const Pipeline&, Tristate wireframe=Tristate::INHERIT);

        void                            erase(const Buffer&);

        uint64_t                        frame_number() const { return m_tick; }

            //! Returns the name of the GPU/physical device
        std::string_view                gpu_name() const;

            //! Returns the type of the GPU/physical device
        VkPhysicalDeviceType            gpu_type() const;
        
        VkQueue                         graphic_queue(uint32_t i=0) const;
        uint32_t                        graphic_queue_count() const;
        uint32_t                        graphic_queue_family() const;
        bool                            graphic_queue_valid() const;

        Expect<ViImage>                 image(uint64_t) const;

        uint32_t                        max_memory_allocation_count() const;
        uint32_t                        max_push_constants_size() const;
        uint32_t                        max_viewports() const;
        
        //! Finds the pipeline
        //! \note the Reference is only good to the next create()
        const ViPipeline&               pipeline(uint64_t) const;
        
        PresentMode                     present_mode() const { return m_presentMode; }
        
        const std::set<PresentMode>&    present_modes_available() const { return m_presentModes; }

        VkQueue                         present_queue(uint32_t i=0) const;
        uint32_t                        present_queue_count() const;
        uint32_t                        present_queue_family() const;
        bool                            present_queue_valid() const;
        


        VkRenderPass                    render_pass() const;

        void                            trigger_rebuild();
        
            //! Sets the background color
        void                            set_clear_color(const RGBA4F&);
        
        void                            set_present_mode(PresentMode);

        //! Finds the shader
        Expect<ViShader>                shader(uint64_t) const;
        

        VkSurfaceKHR                    surface() const { return m_surface; }

        Expect<VkSurfaceCapabilitiesKHR>    surface_capabilities() const;

        VkColorSpaceKHR                 surface_color_space() const { return m_surfaceColorSpace; }
        VkColorSpaceKHR                 surface_color_space(VkFormat) const;
        VkFormat                        surface_format() const { return m_surfaceFormat; }

        bool                            supports_surface(VkFormat) const;
        bool                            supports_present(PresentMode) const;

        VkRect2D                        swapchain_def_scissor() const;
        VkViewport                      swapchain_def_viewport() const;
        uint32_t                        swapchain_height() const;
        uint32_t                        swapchain_image_count() const;
        uint32_t                        swapchain_min_image_count() const;
        uint32_t                        swapchain_width() const;
        
        Expect<ViTexture>               texture(uint64_t) const;
        
        uint64_t                        tick() const { return m_tick; }

        VkQueue                         video_decode_queue(uint32_t i=0) const;
        uint32_t                        video_decode_queue_count() const;
        uint32_t                        video_decode_queue_family() const;
        bool                            video_decode_queue_valid() const;

        VkQueue                         video_encode_queue(uint32_t i=0) const;
        uint32_t                        video_encode_queue_count() const;
        uint32_t                        video_encode_queue_family() const;
        bool                            video_encode_queue_valid() const;

        // used if no draw function is provided
        virtual void                    record(ViContext&){}

        using CommandFunction   = std::function<void(VkCommandBuffer)>;

        std::error_code                 upload(CommandFunction&&);

    protected:
        Visualizer();
        ~Visualizer();
    
        std::error_code             init_visualizer(const ViewerCreateInfo&, GLFWwindow*);
        void                        kill_visualizer();
        
    
        std::error_code             _ctor(const ViewerCreateInfo&, GLFWwindow*);
        void                        _dtor();
    
        //! Allocates w/o copying
        std::error_code             _allocate(ViBuffer&, size_t, VkBufferUsageFlags, VmaMemoryUsage);
        
        //! Allocates WITH copying
        std::error_code             _allocate(ViBuffer&, const Memory&, VkBufferUsageFlags, VmaMemoryUsage);
    
        
        std::error_code             _create(ViBuffer&, const Buffer&);
        void                        _destroy(ViBuffer&);
    
        std::error_code             _create(ViFrame&);
        void                        _destroy(ViFrame&);

        std::error_code             _create(ViImage&, const Image&);
        void                        _destroy(ViImage&);

        std::error_code             _create(ViPipeline&, const PipelineConfig&);
        void                        _destroy(ViPipeline&);

        
        std::error_code             _create(ViSwapchain&);
        void                        _destroy(ViSwapchain&);
        
        std::error_code             _create(ViTexture&, const ViImage&, const Texture&);
        void                        _destroy(ViTexture&);

        std::error_code             _create(ViThread&);
        void                        _destroy(ViThread&);
        
        std::error_code             _create(ViUpload&, const ViQueues&);
        void                        _destroy(ViUpload&);
        
        std::error_code             _record(ViContext&, uint32_t, DrawFunction use={}); // may have extents (later)
        
        void                        _draw(ViContext&, const Rendered&, const Pipeline&, Tristate);
        
    
        Visualizer(const Visualizer&) = delete;
        Visualizer(Visualizer&&) = delete;
        Visualizer& operator=(const Visualizer&) = delete;
        Visualizer& operator=(Visualizer&&) = delete;
    
        using DKey  = std::pair<uint64_t, uint64_t>;
        using ThingMap      = std::map<DKey,ViThing*>;
        using PipelineMap   = std::unordered_map<uint64_t, ViPipeline*>;
        using ShaderMap     = std::unordered_map<uint64_t, ViShader>;
        using BufferMap     = std::unordered_map<uint64_t, ViBuffer>;
        using TextureMap    = std::unordered_map<uint64_t, ViTexture>;
        using ImageMap      = std::unordered_map<uint64_t, ViImage>;
    
        mutable tbb::spin_rw_mutex          m_mutex;
    
    
        VmaAllocator                        m_allocator             = nullptr;
        VqApp*                              m_app                   = nullptr;
        BufferMap                           m_buffers;
        VkClearValue                        m_clearValue;
        VkCommandPoolCreateFlags            m_cmdPoolCreateFlags    = {};
        ViQueues                            m_compute;
        uint32_t                            m_descriptorCount       = 0;
        VkDevice                            m_device                = nullptr;
        VkPhysicalDeviceFeatures            m_deviceFeatures;
        VkPhysicalDeviceProperties          m_deviceInfo;
        //std::vector<const char*>            m_extensions;
        ViFrame                             m_frames[MAX_FRAMES_IN_FLIGHT];
        ViQueues                            m_graphic;
        VkInstance                          m_instance              = nullptr;
        ImageMap                            m_images;
        VkPhysicalDeviceMemoryProperties    m_memoryInfo;
        VkPhysicalDevice                    m_physical              = nullptr;
        PipelineMap                         m_pipelines;
        ViQueues                            m_present;
        PresentMode                         m_presentMode;
        std::set<PresentMode>               m_presentModes;
        //ViQueues                            m_queues[Queue::COUNT];
        VkRenderPass                        m_renderPass            = nullptr;
        ShaderMap                           m_shaders;
        VkSurfaceKHR                        m_surface               = nullptr;
        std::vector<VkSurfaceFormatKHR>     m_surfaceFormats;
        VkFormat                            m_surfaceFormat;
        VkColorSpaceKHR                     m_surfaceColorSpace;
        ViSwapchain                         m_swapchain;
        
        TextureMap                          m_textures;
            // eventually this will get smarter....
        ThingMap                            m_things;
        ViThread                            m_thread;
        
        uint64_t                            m_tick      = 0ULL;     // Always monotomically incrementing
        ViUpload                            m_upload; // [Queue::COUNT];
        ViQueues                            m_videoDecode;
        ViQueues                            m_videoEncode;
        std::atomic<bool>                   m_rebuildSwap           = { false };
        
    private:
        bool                                m_init                  = false;
        GLFWwindow*                         m_window                = nullptr;

        struct Execution;

        /*! Rebuilds the swapchain
        
            This will rebuild the swapchain, if the flag has been set or forced.
        
            \param[in] force    Forces a rebuild
            \return TRUE if rebuild occured
        */
        void                        _rebuild();
    };

}
