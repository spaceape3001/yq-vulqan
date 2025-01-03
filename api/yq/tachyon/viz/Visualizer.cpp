////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////


/*
    Note, development of any engine in vulkan requires examples/guides.  
        
        1.  https://vulkan-tutorial.com
        2.  https://vkguide.dev
        3.  https://www.saschawillems.de
        
    While this is an independent creation, my own intepretation of the Vulkan,
    there may be similarities to the above.
*/

#include "Visualizer.hxx"
#include "Visualizer.hpp"

#include <yq/errors.hpp>
#include <yq/container/BasicBuffer.hpp>
#include <yq/container/initlist_utils.hpp>
#include <yq/core/ErrorDB.hpp>
#include <yq/util/AutoReset.hpp>

#include <yt/errors.hpp>
#include <yt/logging.hpp>
#include <yq/tachyon/app/ViewerCreateInfo.hpp>
#include <yt/gfx/Raster.hpp>
#include <yt/gfx/ImageViewInfo.hpp>
#include <yq/tachyon/scene/Perspective.hpp>
#include <yq/tachyon/scene/Scene.hpp>
#include <yv/VulqanException.hpp>
#include <yv/VqUtils.hpp>
#include <yq/tachyon/viz/ViBuffer.hpp>
#include <yq/tachyon/viz/ViContext.hpp>
#include <yq/tachyon/viz/ViImage.hpp>
#include <yq/tachyon/viz/ViManager.hpp>
#include <yq/tachyon/viz/ViQueueManager.hpp>
#include <yq/tachyon/viz/ViRendered.hpp>
#include <yq/tachyon/viz/ViSampler.hpp>
#include <yq/tachyon/viz/ViShader.hpp>
#include <yq/tachyon/viz/ViSwapchain.hpp>
#include <yq/tachyon/viz/ViTexture.hpp>
//#include <yq/tachyon/vulqan/VulqanManager.hpp>



#include <GLFW/glfw3.h>

#undef LOCK
#undef WLOCK

#define LOCK        tbb::spin_rw_mutex::scoped_lock _lock(m_mutex, false);
#define WLOCK       tbb::spin_rw_mutex::scoped_lock _lock(m_mutex, true);

namespace yq::tachyon {



    ////////////////////////////////////////////////////////////////////////////////
    //  ViFrame0
    ////////////////////////////////////////////////////////////////////////////////

    namespace {
        uint32_t    nextFrameId()
        {
            static std::atomic<uint32_t>    s_ret{0};
            return ++s_ret;
        }
    }

    ViFrame0::ViFrame0(Visualizer&viz) : m_viz(viz), m_id(nextFrameId())
    {
        try {
            _ctor();
        }
        catch(std::error_code ec)
        {
            _dtor();
            throw;
        }
    }
    
    ViFrame0::~ViFrame0()
    {
        _dtor();
    }

    void    ViFrame0::_ctor()
    {
        if(m_renderFinished)
            throw create_error<"Frame already initialized">();
            
        m_commandPool                   = m_viz.command_pool();
        VqCommandBufferAllocateInfo allocInfo;
        allocInfo.commandPool           = m_commandPool;
        allocInfo.level                 = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandBufferCount    = 1;
        if (vkAllocateCommandBuffers(m_viz.device(), &allocInfo, &m_commandBuffer) != VK_SUCCESS) 
            throw create_error<"Failed to allocate command buffers">();

        VqFenceCreateInfo   fci;
        fci.flags = VK_FENCE_CREATE_SIGNALED_BIT;
        if(vkCreateFence(m_viz.device(), &fci, nullptr,  &m_fence) != VK_SUCCESS)
            throw create_error<"Unable to create fence">();

        VqSemaphoreCreateInfo   info;
        if(vkCreateSemaphore(m_viz.device(), &info, nullptr, &m_imageAvailable) != VK_SUCCESS)
            throw create_error<"Unable to create semaphore!">();
        if(vkCreateSemaphore(m_viz.device(), &info, nullptr, &m_renderFinished) != VK_SUCCESS)
            throw create_error<"Unable to create semaphore!">();
            
        m_rendereds     = std::make_unique<ViRenderedManager>(m_viz, ViRenderedOptions{});
    }
    
    void                ViFrame0::_dtor()
    {
        m_rendereds         = {};

        if(m_commandBuffer && m_commandPool){
            vkFreeCommandBuffers(m_viz.device(), m_commandPool, 1, &m_commandBuffer);
            m_commandBuffer   = nullptr;
        }
        
        if(m_imageAvailable){
            vkDestroySemaphore(m_viz.device(), m_imageAvailable, nullptr);
            m_imageAvailable  = nullptr;
        }
        
        if(m_renderFinished){
            vkDestroySemaphore(m_viz.device(), m_renderFinished, nullptr);
            m_renderFinished  = nullptr;
        }
        
        if(m_fence){
            vkDestroyFence(m_viz.device(), m_fence, nullptr);
            m_fence   = nullptr;
        }
    }

    ViRenderedPtr      ViFrame0::create(const RenderedCPtr&obj)
    {
        if(!m_rendereds)
            return {};
        return m_rendereds -> create(obj);
        //return create(obj, *obj.pipeline());
    }
    
    //ViRenderedCPtr      ViFrame0::create(const RenderedCPtr& obj, const Pipeline& pipe)
    //{
        //if(m_rendereds){
            //m_rendereds -> create(obj, pipe);
        //}
    //}
    
    #if 0
    ViRendered0*         ViFrame0::create(const RenderedCPtr&obj, const PipelineCPtr& pipe)
    {
        {
            LOCK
            auto eq = m_rendereds.equal_range(obj.id());
            for(auto i = eq.first; i != eq.second; ++i){
                if(i->second->m_pipe.m_id == pipe.id())
                    return i->second;
            }
        }

        const ViPipeline0*   vp   = m_viz.create(pipe);
        if(!vp)
            return nullptr;
        
        ViRendered0* p   = new ViRendered0(m_viz, *vp, obj);
        ViRendered0* ret = nullptr;
        
        {
            WLOCK
            auto eq = m_rendereds.equal_range(obj.id());
            for(auto i = eq.first; i != eq.second; ++i){
                if(i->second->m_pipe.m_id == pipe.id()){
                    ret = i->second;
                    break;
                }
            }
            
            if(!ret){
                m_rendereds.insert({ obj.id(), p });
                return p;
            }
        }
        
        delete p;
        return ret;
    }
    
    const ViRendered0*   ViFrame0::lookup(const Rendered&ren, const Pipeline& pipe) const
    {
        {
            LOCK
            auto eq = m_rendereds.equal_range(ren.id());
            for(auto i = eq.first; i != eq.second; ++i){
                if(i->second->m_pipe.m_id == pipe.id())
                    return i->second;
            }
        }
        return nullptr;
    }
    #endif


    ////////////////////////////////////////////////////////////////////////////////
    //  ViThread0
    ////////////////////////////////////////////////////////////////////////////////
    
    ViThread0::ViThread0(Visualizer&viz) : m_viz(viz)
    {
        try {
            _ctor();
        }
        catch(std::error_code ec)
        {
            _dtor();
            throw;
        }
    }
    
    ViThread0::~ViThread0()
    {
        _dtor();
    }
    
    void    ViThread0::_ctor()
    {
        uint32_t      dcount  = m_viz.descriptor_count();
        VkDescriptorPoolSize descriptorPoolSizes[] =
        {
            { VK_DESCRIPTOR_TYPE_SAMPLER, dcount },
            { VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, dcount },
            { VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE, dcount },
            { VK_DESCRIPTOR_TYPE_STORAGE_IMAGE, dcount },
            { VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER, dcount },
            { VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER, dcount },
            { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, dcount },
            { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, dcount },
            { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC, dcount },
            { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC, dcount },
            { VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT, dcount }
        };
        
        size_t  cntDPS  = sizeof(descriptorPoolSizes)/sizeof(VkDescriptorPoolSize);
        
        VqDescriptorPoolCreateInfo descriptorPoolInfo;
        //descriptorPoolInfo.flags         = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT | VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT;
        descriptorPoolInfo.flags         = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT | VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT;
        descriptorPoolInfo.maxSets       = dcount * cntDPS;
        descriptorPoolInfo.poolSizeCount = (uint32_t) cntDPS;
        descriptorPoolInfo.pPoolSizes    = descriptorPoolSizes;
        if(vkCreateDescriptorPool(m_viz.device(), &descriptorPoolInfo, nullptr, &m_descriptors) != VK_SUCCESS)
            throw create_error<"Unable to allocate the descriptor pool">();

        VqCommandPoolCreateInfo poolInfo;
        poolInfo.flags                  = m_viz.command_pool_create_flags();
        
        if(m_viz.graphic_queue_valid()){
            poolInfo.queueFamilyIndex   = m_viz.graphic_queue_family();
            if (vkCreateCommandPool(m_viz.device(), &poolInfo, nullptr, &m_graphics) != VK_SUCCESS) 
                throw create_error<"Failed to create a graphic command pool">();
        }
        if(m_viz.compute_queue_valid()){
            poolInfo.queueFamilyIndex   = m_viz.compute_queue_family();
            if (vkCreateCommandPool(m_viz.device(), &poolInfo, nullptr, &m_compute) != VK_SUCCESS) 
                throw create_error<"Failed to create a compute command pool">();
        }
    }
    
    void    ViThread0::_dtor()
    {
        if(m_descriptors){
            vkDestroyDescriptorPool(m_viz.device(), m_descriptors, nullptr);
            m_descriptors = nullptr;
        }
        if(m_graphics){
            vkDestroyCommandPool(m_viz.device(), m_graphics, nullptr);
            m_graphics = nullptr;
        }
        if(m_compute){
            vkDestroyCommandPool(m_viz.device(), m_compute, nullptr);
            m_compute = nullptr;
        }
    }
    
    ////////////////////////////////////////////////////////////////////////////////
    //  VISUALIZER
    ////////////////////////////////////////////////////////////////////////////////

    Visualizer::Visualizer(const ViewerCreateInfo&vci, GLFWwindow*w, Cleanup& c)  : ViVisualizer(c)
    {
        m_cmdPoolCreateFlags    = VK_COMMAND_POOL_CREATE_TRANSIENT_BIT | VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT; //  | VK_COMMAND_POOL_CREATE_PROTECTED_BIT;
        
        std::error_code     ec  = init_visualizer(vci, w); // != std::error_code();
        if(ec != std::error_code())
            throw ec;
            //throw VulqanException("Unable to initialize");
    }
    
    Visualizer::~Visualizer()
    {
        kill_visualizer();
    }
    
    

    std::error_code             Visualizer::_ctor(const ViewerCreateInfo&vci, GLFWwindow*w)
    {
        std::error_code ec;
    
        InitData   iData(vci);
    
        ec  = _0_app_window_initialize(w);
        if(ec != std::error_code())
            return ec;
        
        ec  = _1_gpu_select_initialize(iData);
        if(ec != std::error_code())
            return ec;

        ec = _2_surface_initialize(iData);
        if(ec != std::error_code())
            return ec;
       
        iData.extensions    = vci.extensions;
        iData.extensions.push_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);

            //  And we need to create them... so request
        ec = _3_queues_create(iData);
        if(ec != std::error_code())
            return ec;
                
        ec = _4_device_init(iData);
        if(ec != std::error_code())
            return ec;

        _3_queues_fetch();

        ec = _5_allocator_init(iData);
        if(ec != std::error_code())
            return ec;

        ec  = _6_manager_init();
        if(ec != std::error_code())
            return ec;

        ec = _7_render_pass_create();
        if(ec != std::error_code())
            return ec;
        
        ec = _8_swapchain_create();
        if(ec != std::error_code())
            return ec;
            
        ec = _9_pipeline_manager_create();
        if(ec != std::error_code())
            return ec;

        //  ================================
        //  GETTING THE QUEUES


        //  ================================
        //  ALLOCATOR


        //  ================================
        //  DESCRIPTOR COUNTS

        m_descriptorCount   = std::max(MIN_DESCRIPTOR_COUNT, vci.descriptors);

        m_thread            = std::make_unique<ViThread0>(*this);

        m_frames.reserve(vci.frames_in_flight);
        for(size_t i=0;i<vci.frames_in_flight;++i)
            m_frames.push_back(std::make_unique<ViFrame0>(*this));
            
        return std::error_code();
    }
    
    void                        Visualizer::_dtor()
    {
        vizInfo << "Visualizer::Destructor";
        m_cleanup.sweep();
        m_frames.clear();
        
        m_thread        = {};
    
        //  Generally in reverse order of initialization

        m_cleanup.sweep();
        if(m_device)
            vkDeviceWaitIdle(m_device);

        _9_pipeline_manager_kill();

        m_cleanup.sweep();
        if(m_device)
            vkDeviceWaitIdle(m_device);

        _8_swapchain_kill();

        m_cleanup.sweep();
        if(m_device)
            vkDeviceWaitIdle(m_device);

        _7_render_pass_kill();

        m_cleanup.sweep();
        if(m_device)
            vkDeviceWaitIdle(m_device);

        _6_manager_kill();

        m_cleanup.sweep();
        if(m_device)
            vkDeviceWaitIdle(m_device);

        _5_allocator_kill();
        _4_device_kill();
        _3_queues_kill();
        _2_surface_kill();
        _1_gpu_select_kill();
        _0_app_window_kill();
    }

    std::error_code             Visualizer::init_visualizer(const ViewerCreateInfo& vci, GLFWwindow* w)
    {
        if(m_init)
            return std::error_code();
            
        std::error_code ec  = _ctor(vci, w);
        if(ec){
            _dtor();
            return ec;
        }
         
        m_init      = true;
        return std::error_code();

    }
    
    void                        Visualizer::kill_visualizer()
    {
        if(!m_init)
            return ;
        _dtor();
        m_init  = false;
    }


    ////////////////////////////////////////////////////////////////////////////////
    //  GETTERS/INFORMATION


    VkCommandBuffer Visualizer::command_buffer() const
    {
        return current_frame0().m_commandBuffer;
    }

    VkCommandPool   Visualizer::command_pool() const
    {
        return m_thread->m_graphics;
    }


    ViFrame0&            Visualizer::current_frame0()
    {
        return *(m_frames[m_tick % m_frames.size()]);
    }
    
    const ViFrame0&      Visualizer::current_frame0() const
    {
        return const_cast<Visualizer*>(this)->current_frame0();
    }

    VkDescriptorPool    Visualizer::descriptor_pool() const
    {
        return m_thread->m_descriptors;
    }

    
    ViFrame0&            Visualizer::frame0(int32_t i)
    {
        uint64_t    tick    = (uint64_t)((int64_t) m_tick + i);
        return *(m_frames[tick % m_frames.size() ]);
    }
    
    const ViFrame0&      Visualizer::frame0(int32_t i) const
    {
        return const_cast<Visualizer*>(this)->frame0(i);
    }

    ViFrame0&            Visualizer::next_frame0()
    {
        return *(m_frames[(m_tick+1) % m_frames.size()]);
    }
    
    const ViFrame0&      Visualizer::next_frame0() const
    {
        return const_cast<Visualizer*>(this)->next_frame0();
    }


    ////////////////////////////////////////////////////////////////////////////////
    //  RENDERING

    std::error_code     Visualizer::_record(ViContext& u, uint32_t imageIndex, const DrawFunctions& fcn)
    {
        VqCommandBufferBeginInfo beginInfo;
        beginInfo.flags = 0; // Optional
        beginInfo.pInheritanceInfo = nullptr; // Optional

        if (vkBeginCommandBuffer(u.command_buffer, &beginInfo) != VK_SUCCESS)
            return create_error<"Failed to begin recording command buffer">();

        VqRenderPassBeginInfo renderPassInfo;
        renderPassInfo.renderPass = render_pass();
        renderPassInfo.framebuffer = m_swapchain->framebuffer(imageIndex);
        renderPassInfo.renderArea.offset = {0, 0};
        renderPassInfo.renderArea.extent = m_swapchain->extents();

        renderPassInfo.clearValueCount = 1;
        VkClearValue                cv  = m_clearValue;
        renderPassInfo.pClearValues = &cv;
        vkCmdBeginRenderPass(u.command_buffer, &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

        std::error_code     ret;
        try {
            if(fcn.record){
                fcn.record(u);
            }
        }
        catch(std::error_code ec) {
            ret = ec;
        }
            
        vkCmdEndRenderPass(u.command_buffer);
        if (vkEndCommandBuffer(u.command_buffer) != VK_SUCCESS)
            return create_error<"Failed to record command buffer">();
        return ret;
    }

    std::error_code     Visualizer::draw(ViContext& u, const DrawFunctions& fcn)
    {
        static constexpr const uint64_t     kMaxWait = 100'000'000ULL;
    
        if(!m_swapchain){
            vizCritical << "Visualizer::draw ... attempting to draw on a swapchain WITHOUT a swapchain";
            return errors::swapchain_uninitialized();
        }
        
        auto    r1 = auto_reset(u.viz, this);
        ViFrame0&    f   = current_frame0();
        auto    r2  = auto_reset(u.command_buffer, f.m_commandBuffer);
        auto    r3  = auto_reset(u.frame0, &f);

        VkResult        res = VK_SUCCESS;
        
        struct {
            VkFormat    format  = VK_FORMAT_UNDEFINED;
            bool        enable  = false;
        } snapshot;

        if(auto p = std::get_if<bool>(&u.snapshot)){
            snapshot.enable    = *p;
        }
        if(auto p = std::get_if<DataFormat>(&u.snapshot)){
            snapshot.enable = true;
            snapshot.format = (VkFormat) (p->value());
        }
        
        res = vkWaitForFences(m_device, 1, &f.m_fence, VK_TRUE, kMaxWait);   // 100ms is 10Hz
        if(res == VK_TIMEOUT)
            return create_error<"Fence timeout">();
            
        if(snapshot.enable){
            auto r = m_swapchain -> snapshot(m_frameImageIndex, snapshot.format);
            if(r){
                u.snapshot  = r.value();
            } else {
                u.snapshot  = r.error();
            }
        }

        bool    rebuildFlag = m_rebuildSwap.exchange(false);
        if(rebuildFlag){
            _rebuild_swapchain();
            return std::error_code();
        }

        res    = vkAcquireNextImageKHR(m_device, m_swapchain->swapchain(), kMaxWait, f.m_imageAvailable, VK_NULL_HANDLE, &m_frameImageIndex);
        
        switch(res){
        case VK_TIMEOUT:
            return create_error<"Acquire image timeout">();
        case VK_ERROR_OUT_OF_DATE_KHR:
        case VK_SUBOPTIMAL_KHR:
            _rebuild_swapchain();
            return std::error_code();
        case VK_SUCCESS:
            break;
        case VK_ERROR_OUT_OF_HOST_MEMORY:
            return create_error<"Out of host memory">();
        case VK_ERROR_OUT_OF_DEVICE_MEMORY:
            return create_error<"Out of device memory">();
        case VK_ERROR_DEVICE_LOST:
            return create_error<"Device lost">();
        case VK_ERROR_SURFACE_LOST_KHR:
            return create_error<"Surface lost">();
        case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT:
            return create_error<"Full screen exclusive mode lost">();
        default:
            return create_error<"Unexpected error">();
        }
        
        if(fcn.prerecord)
            fcn.prerecord(u);

        vkResetFences(m_device, 1, &f.m_fence);
        vkResetCommandBuffer(u.command_buffer, 0);
        
    
        std::error_code ec = _record(u, m_frameImageIndex, fcn);
        if(ec)
            return ec;
        
        VqSubmitInfo submitInfo;

        VkSemaphore waitSemaphores[] = { f.m_imageAvailable };
        VkPipelineStageFlags waitStages[] = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
        submitInfo.waitSemaphoreCount = 1;
        submitInfo.pWaitSemaphores      = waitSemaphores;
        submitInfo.pWaitDstStageMask    = waitStages;
        submitInfo.commandBufferCount   = 1;
        submitInfo.pCommandBuffers      = &f.m_commandBuffer;

        VkSemaphore signalSemaphores[]  = {f.m_renderFinished};
        submitInfo.signalSemaphoreCount = 1;
        submitInfo.pSignalSemaphores    = signalSemaphores;

        if (vkQueueSubmit(m_graphicsQueue->queue(0), 1, &submitInfo, f.m_fence) != VK_SUCCESS) 
            return create_error<"Failed to submit draw command buffer">();
            
        VqPresentInfoKHR presentInfo;

        VkSwapchainKHR      swapchains[] = { m_swapchain -> swapchain() };

        presentInfo.waitSemaphoreCount = 1;
        presentInfo.pWaitSemaphores = signalSemaphores;
        presentInfo.swapchainCount = 1;
        presentInfo.pSwapchains = swapchains;
        presentInfo.pImageIndices = &m_frameImageIndex;
        presentInfo.pResults = nullptr; // Optional
        vkQueuePresentKHR(m_presentQueue->queue(0), &presentInfo);
        
        ++m_tick;
        return std::error_code();
    }

    void    Visualizer::_draw(ViContext&u, const RenderedCPtr&r, Tristate w)
    {
        //const auto&         cfg     = p.config();
        //if(cfg->binding != PipelineBinding::Graphics)     // filter out non-graphics (for now)
            //return ;
        
        u.wireframe       = w;
            
        // TODO ... reduce this down to a single pipeline lookup.... (as the next one is implicit)
        
        //  FOR NOW....
        
        ViRenderedPtr       thing = current_frame0().create(r);
        if(!thing)
            return;
        thing -> update(u);
        thing -> record(u);
    }

    void    Visualizer::draw_object(ViContext&u, const RenderedCPtr&r, Tristate w)
    {
        if(!r)
            return ;
        _draw(u, r, w);
    }

    void    Visualizer::draw_scene(ViContext& u, const Scene0&sc, const Perspective0& p)
    {
        if(u.viz != this) //  fast reject
            return ;
        if(!p.camera)
            return ;
            
        auto r1 = auto_reset(u.time, sc.utime);

#if 0        
    // temporary for the rename 
        Camera::Values      cparams;
        if(p.screen){
            cparams.screen = *p.screen;
        } else {
            cparams.screen  = Size2D((double) m_frameBufferSize.x, (double) m_frameBufferSize.y);
        }
        
        auto r2 = auto_reset(u.world2eye, p.camera->world2screen(cparams));
#endif
        
        for(auto& r : sc.things){
            if(!r)
                continue;
            draw_object(u, r, p.wireframe);
        }
    }

    void               Visualizer::update(ViContext&u, const Scene0&sc)
    {
        if(u.frame0){
            for(auto& r : sc.things){
                const Pipeline*pipe    = r->pipeline();
                if(!pipe)
                    continue;
                    
                ViRenderedPtr  rr  = u.frame0 -> create(r);
                if(!rr)
                    continue;
                rr -> update(u);
                rr -> descriptors();
            }
        }
    }
}
