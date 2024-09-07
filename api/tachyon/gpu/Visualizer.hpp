////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>

#include <yq-toolbox/basic/Guarded.hpp>
#include <yq-toolbox/typedef/rgba.hpp>

#include <tachyon/enum/PresentMode.hpp>
#include <yq-vulqan/basic/Tristate.hpp>
#include <yq-vulqan/typedef/buffer.hpp>
#include <yq-vulqan/typedef/image.hpp>
#include <yq-vulqan/typedef/shader.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

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
    struct ViRenderPass;
    struct ViSwapchain;
    struct ViPipeline;
    struct ViFrame;
    struct ViTexture;
    struct ViThread;
    struct ViUpload;

    class Memory;
    

    
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
        
        
        using DrawFunction              = std::function<void(ViContext&)>;
    
    
        //  since this is "stolen", demoted
        GLFWwindow*                     _window() const { return m_window; }
        VmaAllocator                    allocator() const { return m_allocator; }
        VkDevice                        device() const { return m_device; }
        VkDevice                        logical() const { return m_device; }
        VkInstance                      instance() const { return m_instance; }
        VkPhysicalDevice                physical() const { return m_physical; }

        //! Finds the buffer
        Expect<ViBuffer>                buffer(uint64_t) const;

        RGBA4F                          clear_color() const;

        VkCommandBuffer                 command_buffer() const;
        VkCommandPool                   command_pool() const;
        
        VkCommandPoolCreateFlags        command_pool_create_flags() const { return m_cmdPoolCreateFlags; }

        VkQueue                         compute_queue(uint32_t i=0) const;
        uint32_t                        compute_queue_count() const;
        uint32_t                        compute_queue_family() const;
        bool                            compute_queue_valid() const;

        //! Creates the buffer
        Expect<ViBuffer>                create(const Buffer&);

        /*! Creates the shader
        
            This imports the shader onto the GPU device.  
            
            \note Once imported, this shader cannot be removed and will persist 
            to the end of the visualizer's lifespan.
        */
        Expect<ViShader>                create(const Shader&);

        Expect<ViImage>                 create(const Image&);  // temporary name until texture's altered

        //! Creates the pipeline
        //! \note Reference is only good to the next create()
        const ViPipeline*               create(const Pipeline&);
        
        Expect<ViTexture>               create(const Texture&);
        
        //! Gets the current frame
        //! \note will return INVALID reference if construction failed!
        ViFrame&                        current_frame();

        //! Gets the current frame
        //! \note will return INVALID reference if construction failed!
        const ViFrame&                  current_frame() const;

        uint32_t                        descriptor_count() const { return m_descriptorCount; }
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

        Expect<VkFormat>                find_depth_format() const;

        Expect<VkFormat>                find_supported_format(std::span<const VkFormat>, VkImageTiling, VkFormatFeatureFlags) const;
        Expect<VkFormat>                find_supported_format(std::initializer_list<VkFormat>, VkImageTiling, VkFormatFeatureFlags) const;

        //! Gets the frame relative to current
        //! \note will return INVALID reference if construction failed!
        ViFrame&                        frame(int32_t);

        //! Gets the frame relative to current
        //! \note will return INVALID reference if construction failed!
        const ViFrame&                  frame(int32_t) const;

        uint64_t                        frame_number() const { return m_tick; }
        
        size_t                          frames_in_flight() const { return m_frames.size(); }

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
        
        //! Gets the next frame
        //! \note will return INVALID reference if construction failed!
        ViFrame&                        next_frame();

        //! Gets the next frame
        //! \note will return INVALID reference if construction failed!
        const ViFrame&                  next_frame() const;
        
        //! Finds the pipeline
        //! \note do NOT hold onto the reference!
        const ViPipeline*               pipeline(uint64_t) const;
        
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
        
        void                            update(ViContext&, const Scene&);
        
        operator ViVisualizer& () { return m_dedicated; }

    protected:
        Visualizer();
        ~Visualizer();

        virtual void                    prerecord(ViContext&){}
    
        std::error_code             init_visualizer(const ViewerCreateInfo&, GLFWwindow*);
        void                        kill_visualizer();
        
    
        std::error_code             _ctor(const ViewerCreateInfo&, GLFWwindow*);
        void                        _dtor();

        std::error_code             _create(ViTexture&, const ViImage&, const Texture&);
        void                        _destroy(ViTexture&);

        std::error_code             _record(ViContext&, uint32_t, DrawFunction use={}); // may have extents (later)
        
        void                        _draw(ViContext&, const Rendered&, const Pipeline&, Tristate);
        
        
    
        Visualizer(const Visualizer&) = delete;
        Visualizer(Visualizer&&) = delete;
        Visualizer& operator=(const Visualizer&) = delete;
        Visualizer& operator=(Visualizer&&) = delete;
    
        //using DKey  = std::pair<uint64_t, uint64_t>;
        using RenderedMap   = std::unordered_multimap<uint64_t,ViRendered*>;
        using PipelineMap   = std::unordered_map<uint64_t, ViPipeline*>;
        using ShaderMap     = std::unordered_map<uint64_t, ViShader>;
        using BufferMap     = std::unordered_map<uint64_t, ViBuffer>;
        using TextureMap    = std::unordered_map<uint64_t, ViTexture>;
        using ImageMap      = std::unordered_map<uint64_t, ViImage>;
        using FrameArray    = std::vector<std::unique_ptr<ViFrame>>;

        using CleanupFunction               = std::function<void()>;
        using CleanupVector                 = std::vector<CleanupFunction>;
        using CleanupMap                    = std::unordered_map<uint64_t, CleanupVector*>;
    
        mutable tbb::spin_rw_mutex          m_mutex;
        
        ViVisualizer                        m_dedicated;
    
        VmaAllocator                       &m_allocator             = m_dedicated.allocator;
        VqApp*                              m_app                   = nullptr;
        BufferMap                           m_buffers;
        CleanupVector                       m_cleanup;                  // keep it one until performance bottlenecks
        VkClearValue                        m_clearValue;
        VkCommandPoolCreateFlags            m_cmdPoolCreateFlags    = {};
        ViQueues*                           m_compute               = nullptr;
        uint32_t                            m_descriptorCount       = 0;
        VkDevice                           &m_device                = m_dedicated.device;
        VkPhysicalDeviceFeatures            m_deviceFeatures;
        VkPhysicalDeviceProperties          m_deviceInfo;
        //std::vector<const char*>            m_extensions;
        FrameArray                          m_frames;
        ViQueues*                           m_graphic               = nullptr;
        VkInstance                         &m_instance              = m_dedicated.instance;
        ImageMap                            m_images;
        VkPhysicalDeviceMemoryProperties    m_memoryInfo;
        VkPhysicalDevice                   &m_physical              = m_dedicated.gpu;
        PipelineMap                         m_pipelines;
        ViQueues*                           m_present               = nullptr;
        PresentMode                         m_presentMode;
        std::set<PresentMode>               m_presentModes;
        std::vector<Ref<ViQueues>>          m_queues;
        std::unique_ptr<ViRenderPass>       m_renderPass;
        ShaderMap                           m_shaders;
        VkSurfaceKHR                       &m_surface               = m_dedicated.surface;
        std::vector<VkSurfaceFormatKHR>     m_surfaceFormats;
        VkFormat                            m_surfaceFormat;
        VkColorSpaceKHR                     m_surfaceColorSpace;
        std::unique_ptr<ViSwapchain>        m_swapchain;
        
        TextureMap                          m_textures;
            // eventually this will get smarter....
        std::unique_ptr<ViThread>           m_thread;
        
        uint64_t                            m_tick      = 0ULL;     // Always monotomically incrementing
        std::unique_ptr<ViUpload>           m_upload; // [Queue::COUNT];
        ViQueues*                           m_videoDecode           = nullptr;
        ViQueues*                           m_videoEncode           = nullptr;
        std::atomic<bool>                   m_rebuildSwap           = { false };
        

    private:
        bool                                m_init                  = false;
        GLFWwindow*&                        m_window                = m_dedicated.window;

        struct Execution;

        /*! Rebuilds the swapchain
        
            This will rebuild the swapchain, if the flag has been set or forced.
        
            \param[in] force    Forces a rebuild
            \return TRUE if rebuild occured
        */
        void                        _rebuild();
    };

}
