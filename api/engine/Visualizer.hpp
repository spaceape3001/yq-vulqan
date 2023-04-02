////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL's QT UTILITIES
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/UniqueID.hpp>
#include <basic/Guarded.hpp>

#include <engine/preamble.hpp>
#include <tachyon/ViewerCreateInfo.hpp>
#include <tachyon/host/Monitor.hpp>
#include <tachyon/enum/PresentMode.hpp>
#include <tachyon/gpu/Visualizer.hpp>
#include <tachyon/gpu/ViQueues.hpp>
#include <engine/vulqan/VqPipeline.hpp>
#include <math/preamble.hpp>

#include <vk_mem_alloc.h>
#include <MyImGui.hpp>

#include <tbb/spin_rw_mutex.h>

#include <atomic>
#include <set>
#include <thread>

struct GLFWwindow;


namespace yq {
    namespace engine {
        class Viewer;
        struct ViewerCreateInfo;
        struct VqObject;
        
        using ViTick    = std::atomic<uint64_t>;
        
        using tachyon::ViQueues;
        
        
        struct ViShader : public RefCount {
            VkDevice                device  = nullptr;
            VkShaderModule          shader  = nullptr;
            mutable ViTick          tick    = 0;
            VkShaderStageFlagBits   mask    = {};
            
            ViShader();
            ~ViShader();
        };
        
        using ViShaderCPtr  = Ref<const ViShader>;


        struct ViBuffer : not_copyable, not_moveable {
            std::unique_ptr<VqBuffer>   vq;
            uint64_t                    rev = 0;
            
            ViBuffer();
            ~ViBuffer();
        };

        struct ViBufferMap : not_copyable, not_moveable {
            std::map<uint64_t, ViBuffer*>    buffers;
            std::pair<ViBuffer*,bool>    buffer(uint64_t i)
            {
                auto j = buffers.find(i);
                if(j!=buffers.end())
                    return {j->second,false};
                ViBuffer*p  = new ViBuffer;
                buffers[i] = p;
                return {p,true};
            }
            
            ViBufferMap();
            ~ViBufferMap();
        };

        struct ViPipeline : public ViBufferMap {
            std::unique_ptr<VqPipeline> vq;
            
            ViPipeline();
            ~ViPipeline();
        };
        
        struct ViObject : public ViBufferMap {
        
            ViObject();
            ~ViObject();
        };
        
        
            // eventually multithread...
        struct ViThread {
            Visualizer*         viz                 = nullptr;
            VkDescriptorPool    descriptors         = nullptr;
            VkCommandPool       graphic             = nullptr;
            VkCommandPool       compute             = nullptr;
            
            ViThread(Visualizer*);
            ~ViThread();
            void    dtor();
        };
        
            //  and so we can be more efficient in rendering
        struct ViFrame {
            Visualizer*             viz             = nullptr;
            VkCommandBuffer         commandBuffer   = nullptr;
            VkSemaphore             imageAvailable  = nullptr;
            VkSemaphore             renderFinished  = nullptr;
            VkFence                 fence           = nullptr;
            
            ViFrame(Visualizer*);
            ~ViFrame();
            void    dtor();
        };
        
        struct ViSwapchain {
            Visualizer*                 viz             = nullptr;
            VkSwapchainKHR              swapchain       = nullptr;
            VkExtent2D                  extents         = {};
            uint32_t                    minImageCount   = 0;
            uint32_t                    imageCount      = 0;
            std::vector<VkImage>        images;
            std::vector<VkImageView>    imageViews;
            std::vector<VkFramebuffer>  frameBuffers;
            VkSurfaceCapabilitiesKHR    capabilities;

            ViSwapchain(Visualizer*);
            ~ViSwapchain();
            void        dtor();
            VkRect2D    def_scissor() const;
            VkViewport  def_viewport() const;
            uint32_t    width() const;
            uint32_t    height() const;
        };
        
        template <typename T>
        struct ViMap {
            std::map<uint64_t, T>           map;
            mutable tbb::spin_rw_mutex      mutex;
        };
        

        /*! \brief Visualizer is the private data for the viewer
                
            This structure is the raw vulkan/GLFW/etc
            
            \note Eventually this will merge into viewer itself
        */
        struct Visualizer : public tachyon::Visualizer {
            alignas(64) ViMap<ViShaderCPtr>     m_shaders;
        
            Viewer*                             m_viewer                = nullptr;
            uint32_t                            m_descriptorCount       = 0;
            VkCommandPoolCreateFlags            m_cmdPoolCreateFlags    = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
            std::unique_ptr<ViThread>           m_thread;
            VkRenderPass                        m_renderPass            = nullptr;
            
            uint64_t                            m_tick                  = 0;
            ViFrame*                            m_frames[MAX_FRAMES_IN_FLIGHT]  = {};
            ViSwapchain*                        m_swapchain             = nullptr;
            
            
            ViShaderCPtr                        shader(const ShaderSpec&);
            ViShaderCPtr                        shader(uint64_t) const;
            size_t                              shader_count() const;
            void                                shader_purge(uint64_t);
            
            
            //std::thread         builder;
            //uint64_t            pad[8];
            //std::atomic<bool>   terminating                 = false;
            
            std::map<uint64_t, ViPipeline*>     pipelines;
            std::map<uint64_t, ViObject*>       objects;
            
            std::pair<ViPipeline*,bool>     pipeline(uint64_t i);
            std::pair<ViObject*,bool>       object(uint64_t i);
            
            void    run();
            
            
            Visualizer(const ViewerCreateInfo&, Viewer*);
            ~Visualizer();
            void                _ctor(const ViewerCreateInfo&);
            void                _dtor();




            bool                        graphic_draw();
            bool                        graphic_record(VkCommandBuffer, uint32_t); // may have extents (later)


            const ViFrame&              frame() const { return *(m_frames[m_tick%MAX_FRAMES_IN_FLIGHT]); }
            ViFrame&                    frame() { return *(m_frames[m_tick%MAX_FRAMES_IN_FLIGHT]); }
            
            bool                        check_rebuild(bool force=false);
            
        };
    }
}
