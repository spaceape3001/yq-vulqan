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
*//*
    Refactor (Dec 2025)
    
    1.  Eliminate validation issues
        a) Semaphore & Queue threading
        b) Image transfer
    2.  Support offscreen rendering 
        a) Likely become primary with swapchain blitting?
    3.  Viewer should *NOT* stall on the waits... so visualization
        requires a task-like object (but don't have to make it multithreaded)
    4.  Widget may then get ticked() way faster than before
    5.  Fix the R/B swapped colors on snapshot too
    6.  Depth Buffers
    
    
    Current violations
    1.  Semaphore, should be one per swapchain image
    
Validation Error: [ VUID-vkCmdDraw-None-09600 ] | MessageID = 0x46582f7b
vkQueueSubmit(): pSubmits[0] command buffer VkCommandBuffer 0x7f98dc306090 expects VkImage 0x360000000036 (subresource: aspectMask = VK_IMAGE_ASPECT_COLOR_BIT, mipLevel = 0, arrayLayer = 0) to be in layout VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL--instead, current layout is VK_IMAGE_LAYOUT_UNDEFINED.
The Vulkan spec states: If a descriptor with type equal to any of VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM, VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM, VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE, VK_DESCRIPTOR_TYPE_STORAGE_IMAGE, or VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT is accessed as a result of this command, all image subresources identified by that descriptor must be in the image layout identified when the descriptor was written (https://vulkan.lunarg.com/doc/view/1.4.328.1/linux/antora/spec/latest/chapters/drawing.html#VUID-vkCmdDraw-None-09600)
Objects: 2
    [0] VkCommandBuffer 0x7f98dc306090
    [1] VkImage 0x360000000036

Validation Error: [ VUID-vkQueueSubmit-pSignalSemaphores-00067 ] | MessageID = 0x539277af
vkQueueSubmit(): pSubmits[0].pSignalSemaphores[0] (VkSemaphore 0x140000000014) is being signaled by VkQueue 0x7f990423b950, but it may still be in use by VkSwapchainKHR 0x30000000003.
Most recently acquired image indices: [0], 1, 2.
(Brackets mark the last use of VkSemaphore 0x140000000014 in a presentation operation.)
Swapchain image 0 was presented but was not re-acquired, so VkSemaphore 0x140000000014 may still be in use and cannot be safely reused with image index 2.
Vulkan insight: See https://docs.vulkan.org/guide/latest/swapchain_semaphore_reuse.html for details on swapchain semaphore reuse. Examples of possible approaches:
   a) Use a separate semaphore per swapchain image. Index these semaphores using the index of the acquired image.
   b) Consider the VK_KHR_swapchain_maintenance1 extension. It allows using a VkFence with the presentation operation.
The Vulkan spec states: Each binary semaphore element of the pSignalSemaphores member of any element of pSubmits must be unsignaled when the semaphore signal operation it defines is executed on the device (https://vulkan.lunarg.com/doc/view/1.4.328.1/linux/antora/spec/latest/chapters/cmdbuffers.html#VUID-vkQueueSubmit-pSignalSemaphores-00067)
Objects: 2
    [0] VkSemaphore 0x140000000014
    [1] VkQueue 0x7f990423b950
    
    From rocks (different threads per viewer)
    
Validation Error: [ UNASSIGNED-Threading-MultipleThreads-Write ] | MessageID = 0xa05b236e
vkQueueSubmit(): THREADING ERROR : object of type VkQueue is simultaneously used in current thread 140224977950400 and thread 140224747443904
Objects: 1
    [0] VkQueue 0x7f88c7112b50
    
    
Validation Error: [ VUID-vkCmdDraw-None-09600 ] | MessageID = 0x46582f7b
vkQueueSubmit(): pSubmits[0] command buffer VkCommandBuffer 0x7fe56bd740d0 expects VkImage 0x50000000005 (subresource: aspectMask = VK_IMAGE_ASPECT_COLOR_BIT, mipLevel = 0, arrayLayer = 0) to be in layout VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL--instead, current layout is VK_IMAGE_LAYOUT_PRESENT_SRC_KHR.
The Vulkan spec states: If a descriptor with type equal to any of VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM, VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM, VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE, VK_DESCRIPTOR_TYPE_STORAGE_IMAGE, or VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT is accessed as a result of this command, all image subresources identified by that descriptor must be in the image layout identified when the descriptor was written (https://vulkan.lunarg.com/doc/view/1.4.328.1/linux/antora/spec/latest/chapters/drawing.html#VUID-vkCmdDraw-None-09600)
Objects: 2
    [0] VkCommandBuffer 0x7fe56bd740d0
    [1] VkImage 0x50000000005

*/

#include "Visualizer.hxx"
#include <yq/tachyon/vulkan/Visualizer.hpp>

#include <yq/errors.hpp>
#include <yq/container/BasicBuffer.hpp>
#include <yq/container/initlist_utils.hpp>
#include <yq/core/ErrorDB.hpp>
#include <yq/util/AutoReset.hpp>

#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/app/ViewerCreateInfo.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/pipeline/ImageViewInfo.hpp>
#include <yq/tachyon/api/Perspective.hpp>
#include <yq/tachyon/api/RenderedData.hpp>
#include <yq/tachyon/api/Scene.hpp>
#include <yq/tachyon/vulkan/VulqanException.hpp>
#include <yq/tachyon/vulkan/VqUtils.hpp>
#include <yq/tachyon/vulkan/ViBuffer.hpp>
#include <yq/tachyon/vulkan/ViContext.hpp>
#include <yq/tachyon/vulkan/ViDescriptorPool.hpp>
#include <yq/tachyon/vulkan/ViImage.hpp>
#include <yq/tachyon/vulkan/ViManager.hpp>
//#include <yq/tachyon/vulkan/ViQueueManager.hpp>
#include <yq/tachyon/vulkan/ViRendered.hpp>
#include <yq/tachyon/vulkan/ViSampler.hpp>
#include <yq/tachyon/vulkan/ViShader.hpp>
#include <yq/tachyon/vulkan/ViSwapchain.hpp>
#include <yq/tachyon/vulkan/ViTexture.hpp>
#include <yq/tachyon/vulkan/VisualizerCreateData.hpp>
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

    ViRenderedPtr      ViFrame0::create(const RenderedSnap* obj, RenderMode rm)
    {
        if(!m_rendereds)
            return {};
        const Pipeline*p    = obj->pipeline(rm);
        if(!p)
            return {};

        ViRenderedPtr ret =  m_rendereds -> create(obj, p);
        if(!ret)
            return {};
        if(ret->pipeline_id() != p->id())
            ret     = m_rendereds -> recreate(obj, p);
        return ret;
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
        m_descriptors   = new ViDescriptorPool(m_viz.device(REF), m_viz.descriptor_count());

        VqCommandPoolCreateInfo poolInfo;
        poolInfo.flags                  = m_viz.command_pool_create_flags();
        
        if(m_viz.graphics_queue_valid()){
            poolInfo.queueFamilyIndex   = m_viz.graphics_queue_family().index;
            if (vkCreateCommandPool(m_viz.device(), &poolInfo, nullptr, &m_graphics) != VK_SUCCESS) 
                throw create_error<"Failed to create a graphic command pool">();
        }
        if(m_viz.compute_queue_valid()){
            poolInfo.queueFamilyIndex   = m_viz.compute_queue_family().index;
            if (vkCreateCommandPool(m_viz.device(), &poolInfo, nullptr, &m_compute) != VK_SUCCESS) 
                throw create_error<"Failed to create a compute command pool">();
        }
    }
    
    void    ViThread0::_dtor()
    {
        m_descriptors   = {};
        if(m_graphics){
            vkDestroyCommandPool(m_viz.device(), m_graphics, nullptr);
            m_graphics = nullptr;
        }
        if(m_compute){
            vkDestroyCommandPool(m_viz.device(), m_compute, nullptr);
            m_compute = nullptr;
        }
    }

    VkDescriptorPool     ViThread0::descriptors() const
    {
        if(m_descriptors)
            return m_descriptors->descriptor_pool();
        return nullptr;
    }
    
    ////////////////////////////////////////////////////////////////////////////////
    //  VISUALIZER
    ////////////////////////////////////////////////////////////////////////////////

    Visualizer::Visualizer(const CreateData& vcd) : ViVisualizer(vcd)
    {
        m_cmdPoolCreateFlags    = VK_COMMAND_POOL_CREATE_TRANSIENT_BIT | VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT; //  | VK_COMMAND_POOL_CREATE_PROTECTED_BIT;
        
        std::error_code     ec  = _init(vcd);
        if(ec != std::error_code())
            throw ec;
    }
    
    Visualizer::~Visualizer()
    {
        _kill();
    }
    
    

        ///////////////////////////
        
    std::error_code     Visualizer::_init(const CreateData& vcd)
    {
        //  old hack....
        m_descriptorCount   = std::max(MIN_DESCRIPTOR_COUNT, vcd.viewer.descriptors);

        m_thread            = std::make_unique<ViThread0>(*this);

        m_frames.reserve(vcd.viewer.frames_in_flight);
        for(size_t i=0;i<vcd.viewer.frames_in_flight;++i)
            m_frames.push_back(std::make_unique<ViFrame0>(*this));
            
        m_init  = true;
        return std::error_code();
    }
    
    void                Visualizer::_kill()
    {
        if(m_device)
            m_device->cleanup(SWEEP);
        m_frames.clear();
        m_thread        = {};
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
        return m_thread->descriptors();
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
        VkClearValue                cv  = (u.clear.alpha >= 0) ? vqClearValue(u.clear) : (VkClearValue) m_clearValue;
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
        
        res = vkWaitForFences(device(), 1, &f.m_fence, VK_TRUE, kMaxWait);   // 100ms is 10Hz
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

        res    = vkAcquireNextImageKHR(device(), m_swapchain->swapchain(), kMaxWait, f.m_imageAvailable, VK_NULL_HANDLE, &m_frameImageIndex);
        
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

        vkResetFences(device(), 1, &f.m_fence);
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

        if (vkQueueSubmit(graphics_queue(), 1, &submitInfo, f.m_fence) != VK_SUCCESS) 
            return create_error<"Failed to submit draw command buffer">();
            
        VqPresentInfoKHR presentInfo;

        VkSwapchainKHR      swapchains[] = { m_swapchain -> swapchain() };

        presentInfo.waitSemaphoreCount = 1;
        presentInfo.pWaitSemaphores = signalSemaphores;
        presentInfo.swapchainCount = 1;
        presentInfo.pSwapchains = swapchains;
        presentInfo.pImageIndices = &m_frameImageIndex;
        presentInfo.pResults = nullptr; // Optional
        vkQueuePresentKHR(present_queue(), &presentInfo);
        
        ++m_tick;
        return std::error_code();
    }

#if 0
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
#endif
}
