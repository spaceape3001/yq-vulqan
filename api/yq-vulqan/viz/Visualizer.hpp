////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//#include <tachyon/preamble.hpp>

#include <yq-toolbox/basic/Guarded.hpp>

#include <yq-vulqan/viewer/PresentMode.hpp>
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

    //struct ViImage;
    struct ViRendered;
    struct ViRenderPass;
    struct ViSwapchain;
    struct ViPipeline;
    struct ViFrame;
    struct ViTexture;
    struct ViThread;
    struct ViUpload;
    
    struct ViContext;
    
    class Memory;
    class Rendered;
    class Pipeline;
    class Texture;
    class Scene;
    
    struct Perspective;

    class Visualizer : public ViVisualizer  {
    public:
        
        
        using DrawFunction              = std::function<void(ViContext&)>;


        VkCommandBuffer                 command_buffer() const;
        VkCommandPool                   command_pool() const;
        
        VkCommandPoolCreateFlags        command_pool_create_flags() const { return m_cmdPoolCreateFlags; }


        //! Creates the pipeline
        //! \note Reference is only good to the next create()
        const ViPipeline*               create(const Pipeline&);
        
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

        //! Gets the frame relative to current
        //! \note will return INVALID reference if construction failed!
        ViFrame&                        frame(int32_t);

        //! Gets the frame relative to current
        //! \note will return INVALID reference if construction failed!
        const ViFrame&                  frame(int32_t) const;

        uint64_t                        frame_number() const { return m_tick; }
        
        size_t                          frames_in_flight() const { return m_frames.size(); }

        
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

        
        void                            trigger_rebuild();
        
        void                            set_present_mode(PresentMode);

        VkRect2D                        swapchain_def_scissor() const;
        VkViewport                      swapchain_def_viewport() const;
        uint32_t                        swapchain_height() const;
        uint32_t                        swapchain_image_count() const;
        uint32_t                        swapchain_min_image_count() const;
        uint32_t                        swapchain_width() const;

        // used if no draw function is provided
        virtual void                    record(ViContext&){}

        void                            update(ViContext&, const Scene&);
        
    protected:
        //friend struct ViPipeline;
        //friend struct ViRendered;
    
        Visualizer();
        ~Visualizer();

        virtual void                    prerecord(ViContext&){}
    
        std::error_code             init_visualizer(const ViewerCreateInfo&, GLFWwindow*);
        void                        kill_visualizer();
        
    
        std::error_code             _ctor(const ViewerCreateInfo&, GLFWwindow*);
        void                        _dtor();

        //std::error_code             _create(ViTexture&, const ViImage&, const Texture&);
        //void                        _destroy(ViTexture&);

        std::error_code             _record(ViContext&, uint32_t, DrawFunction use={}); // may have extents (later)
        
        void                        _draw(ViContext&, const Rendered&, const Pipeline&, Tristate);
        
        
    
        Visualizer(const Visualizer&) = delete;
        Visualizer(Visualizer&&) = delete;
        Visualizer& operator=(const Visualizer&) = delete;
        Visualizer& operator=(Visualizer&&) = delete;
    
        //using DKey  = std::pair<uint64_t, uint64_t>;
        using RenderedMap   = std::unordered_multimap<uint64_t,ViRendered*>;
        using PipelineMap   = std::unordered_map<uint64_t, ViPipeline*>;
        using TextureMap    = std::unordered_map<uint64_t, ViTexture>;
        using ImageMap      = std::unordered_map<uint64_t, ViImage>;
        using FrameArray    = std::vector<std::unique_ptr<ViFrame>>;

        //using CleanupMap                    = std::unordered_map<uint64_t, CleanupVector*>;
    
        VkCommandPoolCreateFlags            m_cmdPoolCreateFlags    = {};
        uint32_t                            m_descriptorCount       = 0;
        //std::vector<const char*>            m_extensions;
        FrameArray                          m_frames;
        ImageMap                            m_images;
        PipelineMap                         m_pipelines;
        //PresentMode                         m_presentMode;
        //std::unique_ptr<ViRenderPass>       m_renderPass;
        std::unique_ptr<ViSwapchain>        m_swapchain;
        
        TextureMap                          m_textures;
            // eventually this will get smarter....
        std::unique_ptr<ViThread>           m_thread;
        
        //std::unique_ptr<ViUpload>           m_upload; // [Queue::COUNT];
        std::atomic<bool>                   m_rebuildSwap           = { false };
        

    private:
        bool                                m_init                  = false;

        struct Execution;

        /*! Rebuilds the swapchain
        
            This will rebuild the swapchain, if the flag has been set or forced.
        
            \param[in] force    Forces a rebuild
            \return TRUE if rebuild occured
        */
        void                        _rebuild();
    };

}
