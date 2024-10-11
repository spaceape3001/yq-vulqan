////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//#include <tachyon/preamble.hpp>

#include <yq/core/Guarded.hpp>

#include <yq-vulqan/viewer/PresentMode.hpp>
#include <yq-vulqan/basic/Tristate.hpp>
#include <yq-vulqan/typedef/buffer.hpp>
#include <yq-vulqan/typedef/image.hpp>
#include <yq-vulqan/typedef/rendered.hpp>
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
    //struct ViRendered0;
    struct ViRenderPass;
    struct ViSwapchain;
    //struct ViPipeline0;
    struct ViFrame0;
    struct ViTexture;
    struct ViThread0;
    struct ViUpload;
    
    struct ViContext;
    
    //class Memory;
    //class Rendered;
    //class Pipeline;
    //class Texture;
    class Scene;
    
    struct Perspective;

    class Visualizer : public ViVisualizer  {
    public:
        
        
        using DrawFunction              = std::function<void(ViContext&)>;


        VkCommandBuffer                 command_buffer() const;
        VkCommandPool                   command_pool() const;
        
        VkCommandPoolCreateFlags        command_pool_create_flags() const { return m_cmdPoolCreateFlags; }


        //! Gets the current frame
        //! \note will return INVALID reference if construction failed!
        ViFrame0&                       current_frame0();

        //! Gets the current frame
        //! \note will return INVALID reference if construction failed!
        const ViFrame0&                 current_frame0() const;

        uint32_t                        descriptor_count() const { return m_descriptorCount; }
        VkDescriptorPool                descriptor_pool() const override;

        /*! \brief "Draws" 
        
            \note Nothing stops recursion... DON'T
        */
        std::error_code                 draw(ViContext&, DrawFunction use={});
        
        void                            draw_scene(ViContext&, const Scene&, const Perspective&);
        
        //! Draw a specific item, matrix assumed correct
        void                            draw_object(ViContext&, const RenderedCPtr&, Tristate wireframe=Tristate::INHERIT);

        //! Draw a specific item, matrix assumed correct, with given pipeline
        //void                            draw_object(ViContext&, const Rendered&, const Pipeline&, Tristate wireframe=Tristate::INHERIT);

        //! Gets the frame relative to current
        //! \note will return INVALID reference if construction failed!
        ViFrame0&                       frame0(int32_t);

        //! Gets the frame relative to current
        //! \note will return INVALID reference if construction failed!
        const ViFrame0&                 frame0(int32_t) const;

        uint64_t                        frame_number() const { return m_tick; }
        
        size_t                          frames_in_flight() const { return m_frames.size(); }

        
        //! Gets the next frame
        //! \note will return INVALID reference if construction failed!
        ViFrame0&                        next_frame0();

        //! Gets the next frame
        //! \note will return INVALID reference if construction failed!
        const ViFrame0&                  next_frame0() const;
        


        // used if no draw function is provided
        virtual void                    record(ViContext&){}

        void                            update(ViContext&, const Scene&);
        
    protected:
        //friend struct ViPipeline0;
        //friend struct ViRendered0;
    
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
        
        void                        _draw(ViContext&, const RenderedCPtr&, Tristate);
    
        Visualizer(const Visualizer&) = delete;
        Visualizer(Visualizer&&) = delete;
        Visualizer& operator=(const Visualizer&) = delete;
        Visualizer& operator=(Visualizer&&) = delete;
    
        //using RenderedMap   = std::unordered_multimap<uint64_t,ViRendered0*>;
        using FrameArray    = std::vector<std::unique_ptr<ViFrame0>>;

        VkCommandPoolCreateFlags            m_cmdPoolCreateFlags    = {};
        uint32_t                            m_descriptorCount       = 0;
        FrameArray                          m_frames;
        
            // eventually this will get smarter....
        std::unique_ptr<ViThread0>           m_thread;

    private:
        bool                                m_init                  = false;

        struct Execution;

    };

}
