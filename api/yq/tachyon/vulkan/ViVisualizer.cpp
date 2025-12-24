////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/vulkan/ViVisualizer.hpp>

#include <yq/color/RGBA.hpp>
#include <yq/container/initlist_utils.hpp>
#include <yq/text/basic.hpp>
#include <yq/text/join.hpp>

#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/app/ViewerCreateInfo.hpp>
#include <yq/tachyon/pipeline/Buffer.hpp>
#include <yq/tachyon/pipeline/Pipeline.hpp>
#include <yq/tachyon/asset/Sampler.hpp>
#include <yq/tachyon/asset/Shader.hpp>
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/config/vulqan.hpp>
//#include <yq/tachyon/v/VqEnumerations.hpp>
#include <yq/tachyon/vulkan/VqEnums.hpp>
#include <yq/tachyon/vulkan/VqStructs.hpp>
#include <yq/tachyon/vulkan/VqUtils.hpp>
#include <yq/tachyon/vulkan/VulqanManager.hpp>
#include <yq/tachyon/vulkan/ViDevice.hpp>
#include <yq/tachyon/vulkan/ViManager.hpp>
#include <yq/tachyon/vulkan/ViBuffer.hpp>
#include <yq/tachyon/vulkan/ViImage.hpp>
#include <yq/tachyon/vulkan/ViPipeline.hpp>
#include <yq/tachyon/vulkan/ViPipelineLayout.hpp>
#include <yq/tachyon/vulkan/ViProcessor.hpp>
#include <yq/tachyon/vulkan/ViQueueTasker.hpp>
#include <yq/tachyon/vulkan/ViRenderPass.hpp>
#include <yq/tachyon/vulkan/ViSampler.hpp>
#include <yq/tachyon/vulkan/ViShader.hpp>
#include <yq/tachyon/vulkan/ViSurface.hpp>
#include <yq/tachyon/vulkan/ViSwapchain.hpp>
#include <yq/tachyon/vulkan/ViTexture.hpp>
#include <yq/tachyon/vulkan/VisualizerCreateData.hpp>

#include <GLFW/glfw3.h>

#include <algorithm>

namespace yq::tachyon {

    ViVisualizer::ViVisualizer(const CreateData& cfg) : 
        VizBase(Param{
            .color_clear            = cfg.viewer.clear,
            .compute                = cfg.viewer.compute,
            .depth_buffer           = cfg.viewer.depth_buffer,
            .device                 = cfg.device, 
            .graphics               = REQUIRED,
            .graphics_processors    = std::clamp(cfg.viewer.frames_in_flight, MIN_FRAMES_IN_FLIGHT, MAX_FRAMES_IN_FLIGHT),
            .graphics_qidx          = cfg.number,
            .optical_flow           = cfg.viewer.optical_flow,
            .present                = REQUIRED,
            .present_queue          = cfg.present,
            .surface                = cfg.surface->surface(),
            .transfer               = cfg.viewer.transfer,
            .video_decode           = cfg.viewer.video_decode,
            .video_encode           = cfg.viewer.video_encode
        }), 
        m_surface(cfg.surface)
    {
        m_presentMode   = PresentMode::Fifo;
        std::error_code ec  = _init(cfg);
        if(ec != std::error_code()){
            _kill();
            throw ec;
        }
    }
    
    ViVisualizer::~ViVisualizer()
    {
        _kill();
    }

    ///////////////////////////////////////////////////////////////////////////

    std::error_code     ViVisualizer::_7_render_pass_create()
    {
        ViRenderPassPtr     rp  = new ViRenderPass;
        std::error_code ec  = rp -> init(*this, m_surfaceFormat);
        if(ec != std::error_code())
            return ec;
        m_renderPass    = (ViRenderPassCPtr) rp;
        vizDebug << "ViVisualizer: Created the render pass";
        return {};
    }
    
    void               ViVisualizer::_7_render_pass_kill()
    {
        m_renderPass    = nullptr;
        vizDebug << "ViVisualizer: Destroyed the render pass";
    }

    std::error_code    ViVisualizer:: _8_swapchain_create()
    {
        ViSwapchainPtr      sp = new ViSwapchain;
        std::error_code ec = sp->init(*this);
        if(ec != std::error_code())
            return ec;
        m_swapchain     = sp;
        vizDebug << "ViVisualizer: Created the swapchain";
        return {};
    }
    
    void                ViVisualizer::_8_swapchain_kill()
    {
        m_swapchain     = nullptr;
        vizDebug << "ViVisualizer: Destroyed the swapchain";
    }

    //std::error_code     ViVisualizer::_9_pipeline_manager_create()
    //{
        //ViPipelineOptions   opts{
            ////.swapchain  = m_swapchain
        //};
        ////m_pipelines     = std::make_unique<ViPipelineManager>(*this, opts);
        //vizDebug << "ViVisualizer: Created the pipeline manager";
        //return {};
    //}
    
    //void                ViVisualizer::_9_pipeline_manager_kill()
    //{
        //m_pipelines     = {};
        //vizDebug << "ViVisualizer: Destroyed the pipeline manager";
    //}

    void                ViVisualizer::_rebuild_swapchain()
    {
        ViSwapchainConfig   cfg;
        if(m_swapchain)
            cfg.old_swapchain = m_swapchain -> swapchain();
        ViSwapchainPtr  p   = new ViSwapchain;

        m_device->wait_idle();
        
        std::error_code ec  = p -> init(*this, cfg);
        if(ec != std::error_code()){
            vizWarning << "ViVisualizer unable to initialize new swapchain!  " << ec.message();
            return ;
        }
        m_swapchain     = p;
        vizDebug << "ViVisualizer: Rebuilt the swapchain";
    }

    ///////////////////////////////////////////////////////////////////////////

    std::error_code     ViVisualizer::_init(const CreateData& vcd)
    {
        if(!m_device || !m_device->valid())
            return create_error<"null device">();
        if(!m_surface || !m_surface->valid())
            return create_error<"null surface">();

        for(auto pm : vqGetPhysicalDeviceSurfacePresentModesKHR(physical(), surface()))
            m_presentModes.insert((PresentMode::enum_t) pm);
        m_presentMode           = m_presentModes.contains(vcd.viewer.pmode) ? vcd.viewer.pmode : PresentMode{ PresentMode::Fifo };

        m_surfaceFormats        = vqGetPhysicalDeviceSurfaceFormatsKHR(physical(), surface());
        
        // right now, cheating on format & color space
        m_surfaceFormat         = VK_FORMAT_B8G8R8A8_SRGB;
        m_surfaceColorSpace     = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;

            
        std::error_code     ec;

        ec = _7_render_pass_create();
        if(ec != std::error_code())
            return ec;
            
        ec = _8_swapchain_create();
        if(ec != std::error_code())
            return ec;
            
        //ec = _9_pipeline_manager_create();
        //if(ec != std::error_code())
            //return ec;
        return {};
    }
    
    void                ViVisualizer::_kill()
    {
        if(!m_device->valid())
            return ;
            
        //_9_pipeline_manager_kill();
        //m_device->wait_idle();
        _8_swapchain_kill();
        m_device->wait_idle();
        _7_render_pass_kill();
        m_device->wait_idle();
    }


    ///////////////////////////////////////////////////////////////////////////


    
    PresentMode  ViVisualizer::present_mode() const
    {
        return m_presentMode;
    }

    const std::set<PresentMode>&    ViVisualizer::present_modes_available() const
    {
        return m_presentModes;
    }

    VkRenderPass        ViVisualizer::render_pass() const
    {
        if(m_renderPass)
            return m_renderPass -> render_pass();
        return nullptr;
    }
    
    void        ViVisualizer::set_framebuffer_size(const Size2I&sz)
    {
        if(sz != m_frameBufferSize){
            m_frameBufferSize   = sz;
            m_rebuildSwap       = true;
        }
    }

    void        ViVisualizer::set_present_mode(PresentMode pm)
    {
        if((pm != m_presentMode) && supports_present(pm)){
            m_presentMode   = pm;
            m_rebuildSwap   = true;
        }
    }

    bool        ViVisualizer::supports_surface(VkFormat fmt) const
    {
        for(auto f : m_surfaceFormats)
            if(fmt == f.format)
                return true;
        return false;
    }
    
    bool        ViVisualizer::supports_present(PresentMode pm) const
    {
        return m_presentModes.contains(pm);
    }

    VkSurfaceKHR      ViVisualizer::surface() const 
    { 
        if(m_surface)
            return m_surface -> surface();
        return nullptr;
    }

    VkSurfaceCapabilitiesKHR_x  ViVisualizer::surface_capabilities() const
    {
        VkSurfaceCapabilitiesKHR    ret;
        if(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physical(), surface(), &ret) != VK_SUCCESS)
            return unexpected<"Unable to get surface capabilities">();
        return ret;
    }

    VkColorSpaceKHR  ViVisualizer::surface_color_space() const 
    { 
        return m_surfaceColorSpace; 
    }

    VkColorSpaceKHR ViVisualizer::surface_color_space(VkFormat fmt) const
    {
        for(auto& f : m_surfaceFormats)
            if(fmt == f.format)
                return f.colorSpace;
        return VK_COLOR_SPACE_MAX_ENUM_KHR;
    }
    
    VkFormat    ViVisualizer::surface_format() const 
    { 
        return m_surfaceFormat; 
    }

    VkSwapchainKHR  ViVisualizer::swapchain() const
    {
        if(!m_swapchain)
            return nullptr;
        return m_swapchain->swapchain();
    }

    VkRect2D    ViVisualizer::swapchain_def_scissor() const
    {
        if(!m_swapchain)
            return {};
        return m_swapchain->def_scissor();
    }
    
    VkViewport  ViVisualizer::swapchain_def_viewport() const
    {
        if(!m_swapchain)
            return {};
        return m_swapchain->def_viewport();
    }

    uint32_t    ViVisualizer::swapchain_image_count() const
    {
        if(!m_swapchain)
            return 0;
        return m_swapchain->image_count();
    }

    uint32_t    ViVisualizer::swapchain_height() const
    {
        if(!m_swapchain)
            return 0;
        return m_swapchain->height();
    }

    uint32_t    ViVisualizer::swapchain_min_image_count() const
    {
        if(!m_swapchain)
            return 0;
        return m_swapchain->min_image_count();
    }

    uint32_t    ViVisualizer::swapchain_width() const
    {
        if(!m_swapchain)
            return 0;
        return m_swapchain->width();
    }

    void    ViVisualizer::trigger_rebuild()
    {
        m_rebuildSwap       = true;
    }


}
