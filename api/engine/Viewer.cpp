////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

/*
    YES, we're leveraging the "hello triangle" tutorial
    
    https://vulkan-tutorial.com/
*/

#include "Application.hpp"
#include "Perspective.hpp"
#include "Scene.hpp"
#include "Viewer.hpp"
#include "Visualizer.hpp"

#include <basic/CollectionUtils.hpp>
#include <basic/Logging.hpp>
#include <basic/Safety.hpp>
#include <basic/TextUtils.hpp>
#include <basic/meta/ObjectInfoWriter.hpp>

#include <tachyon/asset/Shader.hpp>

#include <engine/render/IndexBufferObjectInfo.hpp>
#include <engine/render/Pipeline.hpp>
#include <engine/render/PipelineConfig.hpp>
#include <engine/render/PushBufferObjectInfo.hpp>
#include <engine/render/Rendered.hpp>
#include <engine/render/Render3D.hpp>
#include <engine/render/StdPushConstant.hpp>
#include <engine/render/UniformBufferObjectInfo.hpp>
#include <engine/render/VertexBufferObjectInfo.hpp>

#include <engine/vulqan/VqBuffer.hpp>
#include <engine/vulqan/VqPipeline.hpp>


#include <tachyon/gpu/VqException.hpp>
#include <tachyon/gpu/VqLogging.hpp>
#include <tachyon/gpu/VqStructs.hpp>
#include <tachyon/gpu/VqUtils.hpp>

#include <math/shape/Size2.hpp>
#include <math/vector/Vector2.hpp>

#include <algorithm>
#include <cassert>

#include <GLFW/glfw3.h>

#include <MyImGui.hpp>
#include <backends/imgui_impl_vulkan.h>
#include <backends/imgui_impl_glfw.h>

#include <math/shape/Size2.hxx>

YQ_OBJECT_IMPLEMENT(yq::engine::Viewer)


using namespace yq::vulqan;
using namespace yq::tachyon;

namespace yq {
    namespace engine {
        #if 0
        WindowInfo::WindowInfo(std::string_view kname, ObjectInfo& base, const std::source_location& sl) :
            ObjectInfo(kname, base, sl)
        {
        }
        #endif

        ////////////////////////////////////////////////////////////////////////////////

        void  Viewer::callback_character(GLFWwindow* window, unsigned int codepoint)
        {
            ImGui_ImplGlfw_CharCallback(window, codepoint);
        }
        
        void  Viewer::callback_cursor_enter(GLFWwindow* window, int entered)
        {
            ImGui_ImplGlfw_CursorEnterCallback(window, entered);
        }
        
        void  Viewer::callback_cursor_position(GLFWwindow* window, double xpos, double ypos)
        {
            ImGui_ImplGlfw_CursorPosCallback(window, xpos, ypos);
            
            Viewer* v   = (Viewer*) glfwGetWindowUserPointer(window);
            if(v){
                v->m_cursorPos  = { xpos, ypos };
            }
        }
        
        void  Viewer::callback_drop([[maybe_unused]] GLFWwindow* window, [[maybe_unused]] int count, [[maybe_unused]] const char** paths)
        {
        }
        
        void  Viewer::callback_framebuffer_size(GLFWwindow* window, [[maybe_unused]] int width, [[maybe_unused]] int height)
        {
            Viewer    *v  = (Viewer*) glfwGetWindowUserPointer(window);
            if(v){
                v -> m_viz -> trigger_rebuild();
                if(v) [[likely]]
                    v->window_resized();
            }
            yInfo() << "Frame size changed!";
        }
        
        void  Viewer::callback_joystick([[maybe_unused]] int jid, [[maybe_unused]] int event)
        {
            yInfo() << "Joystick callback";
        }
        
        void  Viewer::callback_key(GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
        }
        
        void  Viewer::callback_monitor(GLFWmonitor* monitor, int event)
        {
            ImGui_ImplGlfw_MonitorCallback(monitor, event);
        }
        
        void  Viewer::callback_mouse_button(GLFWwindow* window, int button, int action, int mods)
        {
            ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
            yInfo() << "Mouse button!";
        }
        
        void  Viewer::callback_scroll(GLFWwindow* window, double xoffset, double yoffset)
        {
            ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);
            yInfo() << "Scroll Wheel button!";
        }

        void  Viewer::callback_window_close(GLFWwindow*)
        {
            yInfo() << "Window close requested";
        }
        
        void  Viewer::callback_window_focus(GLFWwindow* window, int focused)
        {
            ImGui_ImplGlfw_WindowFocusCallback(window, focused);
            yInfo() << "Window focus changed!";
        }
        
        void  Viewer::callback_window_iconify(GLFWwindow*, int)
        {
            yInfo() << "Viewer iconified";
        }
        
        void  Viewer::callback_window_maximize(GLFWwindow*, int)
        {
            yInfo() << "Viewer maximized";
        }
        
        void  Viewer::callback_window_position(GLFWwindow*, int, int)
        {
            yInfo() << "Viewer moved!";
        }
        
        void  Viewer::callback_window_refresh(GLFWwindow*)
        {
            yInfo() << "Viewer refresh!"; // (ignoring)
        }
        
        void  Viewer::callback_window_scale(GLFWwindow*, float, float)
        {
            yInfo() << "Viewer rescaled!";
        }
        
        void  Viewer::callback_window_size(GLFWwindow* window, int, int)
        {
            Viewer    *v  = (Viewer*) glfwGetWindowUserPointer(window);
            if(v){
                v -> m_viz -> trigger_rebuild();
                if(v) [[likely]]
                    v->window_resized();
            }
            yInfo() << "Viewer resized!";
        }
        
        void Viewer::poll_events()
        {
            glfwPollEvents();
        }

        //  ----------------------------------------------------------------------------

        Viewer::Viewer(const ViewerCreateInfo&vci)
        {
            try {
                Application::vulkan();
                
                init_window(vci);
                
                glfwSetCharCallback(window(), callback_character);
                glfwSetCursorEnterCallback(window(), callback_cursor_enter);
                glfwSetCursorPosCallback(window(), callback_cursor_position);
                glfwSetDropCallback(window(), callback_drop);
                glfwSetFramebufferSizeCallback(window(), callback_framebuffer_size);
                glfwSetKeyCallback(window(), callback_key);
                [[maybe_unused]] static auto fn2 = glfwSetJoystickCallback( callback_joystick );
                [[maybe_unused]] static auto fn1 = glfwSetMonitorCallback( callback_monitor);
                glfwSetMouseButtonCallback(window(), callback_mouse_button);
                glfwSetScrollCallback(window(), callback_scroll);
                glfwSetWindowCloseCallback(window(), callback_window_close);
                glfwSetWindowContentScaleCallback(window(), callback_window_scale);
                glfwSetWindowFocusCallback(window(), callback_window_focus);
                glfwSetWindowIconifyCallback(window(), callback_window_iconify);
                glfwSetWindowMaximizeCallback(window(), callback_window_maximize);
                glfwSetWindowPosCallback(window(), callback_window_position);
                glfwSetWindowRefreshCallback(window(), callback_window_refresh);
                glfwSetWindowSizeCallback(window(), callback_window_size);

                m_viz   = std::make_unique<Visualizer>(vci,this);
                
                if(vci.imgui){
                    m_imgui = ImGui::CreateContext();

                    ImGui_ImplVulkan_InitInfo vii{};
                    
                    vii.Instance        = m_viz->instance();
                    vii.PhysicalDevice  = m_viz->physical();
                    vii.Device          = m_viz->device();
                    vii.Queue           = m_viz->graphic_queue(0);
                    vii.QueueFamily     = m_viz->graphic_queue_family();
                    vii.MinImageCount   = m_viz->m_swapchain->minImageCount;
                    vii.ImageCount      = m_viz->m_swapchain->imageCount;
                    vii.DescriptorPool  = m_viz->m_thread->descriptors;
                    
                    ImGui::SetCurrentContext(m_imgui);
                    ImGui_ImplGlfw_InitForVulkan(window(), false);
                    ImGui_ImplVulkan_Init(&vii, m_viz->m_renderPass);
                    
                    //  Uploading fonts....
                    
                    VkCommandBuffer cbuffer = m_viz->m_frames[0]->commandBuffer;

                    vkResetCommandPool(m_viz->device(), m_viz->m_thread->graphic, 0);
                    VqCommandBufferBeginInfo begin_info;
                    begin_info.flags |= VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
                    vkBeginCommandBuffer(cbuffer, &begin_info);

                    ImGui_ImplVulkan_CreateFontsTexture(cbuffer);

                    VqSubmitInfo end_info;
                    end_info.commandBufferCount = 1;
                    end_info.pCommandBuffers = &cbuffer;
                    vkEndCommandBuffer(cbuffer);
                    vkQueueSubmit(m_viz->graphic_queue(0), 1, &end_info, VK_NULL_HANDLE);
                    vkDeviceWaitIdle(m_viz->device());
                    ImGui_ImplVulkan_DestroyFontUploadObjects();
                }


                set_clear_color(vci.clear);
                yNotice() << "Using (" << to_string(gpu_type()) << "): " << gpu_name();
            }
            catch(VqException& ex){
                yCritical() << ex.what();
                _dtor();
                throw;
            }
        }
        
        Viewer::~Viewer()
        {
            _dtor();
        }

        void    Viewer::_dtor()
        {
            if(m_imgui){
                ImGui::SetCurrentContext(m_imgui);
                ImGui_ImplVulkan_Shutdown();
                ImGui_ImplGlfw_Shutdown();
                ImGui::DestroyContext(m_imgui);
                ImGui::SetCurrentContext(nullptr);
                m_imgui     = nullptr;
            }
            m_viz           = nullptr;
            kill_window();
        }


        ////////////////////////////////////////////////////////////////////////////////

        bool    Viewer::draw()
        {
            ++m_frameNumber;
            auto start = std::chrono::high_resolution_clock::now();
            if(m_imgui){
                ImGui::SetCurrentContext(m_imgui);
                ImGui_ImplVulkan_NewFrame();
                ImGui_ImplGlfw_NewFrame();
                ImGui::NewFrame();
                draw_imgui();
                ImGui::Render();
            }
            m_viz->graphic_draw();
            auto end   = std::chrono::high_resolution_clock::now();
            m_drawTime          = Second((end-start).count());
            return true;
        }

        void    Viewer::draw_vulqan(VkCommandBuffer)
        {
        }

        void    Viewer::render(VkCommandBuffer buf, const Scene& scene, const Perspective& pr)
        {   
            if(!pr.camera){
                yCritical() << "Camera not detected!\n";
                return ;
            }
    
            CameraParams        cparams;
            cparams.screen      = (Size2D) size();
            glm::dmat4          cam_matrix = pr.camera->world2screen(cparams);
            
            VkPipeline          prev_pipeline   = nullptr;
            StdPushConstant     stdPush;
            
            for(const Rendered* r : scene.things){
                const Pipeline* pipe    = r->pipeline();
                if(!pipe){
                    continue;
                }
                    
                const Render3D *r3  = dynamic_cast<const Render3D*>(r);

                ViPipeline*     vp      = nullptr;
                ViObject*       vo      = nullptr;
                bool            pnew      = false;
                bool            onew      = false;
                
                std::tie( vp, pnew )    = m_viz->pipeline(pipe->id());
                std::tie( vo, onew )    = m_viz->object(r->id());
                
                if(pnew)
                    vp->vq        = std::make_unique<VqPipeline>(*m_viz, pipe->config());
                
                uint32_t            shader_mask = vp->vq->shader_mask();
                Tristate            wireframe   = (r->wireframe() == Tristate::INHERIT) ? pr.wireframe : r->wireframe();
                VkPipeline          vkpipe  = (wireframe == Tristate::YES) ? vp->vq->wireframe() : vp->vq->pipeline();
                VkPipelineLayout    vklay   = vp->vq->layout();
            
                //  =================================================
                //      SET THE PIPELINE
            
                if(vkpipe && (vkpipe != prev_pipeline)){
                    vkCmdBindPipeline(buf, VK_PIPELINE_BIND_POINT_GRAPHICS, vkpipe);
                    prev_pipeline   = vkpipe;
                }
                
                //  =================================================
                //      PUSH THE CONSTANTS

                switch(pipe->push_type()){
                case PushConfigType::Full:
                    if(r3){
                        stdPush.matrix  = cam_matrix * r3->model2world();
                        vkCmdPushConstants(buf, vklay, shader_mask, 0, sizeof(stdPush), &stdPush );
                    }
                    break;
                case PushConfigType::View:
                    stdPush.matrix  = cam_matrix;
                    vkCmdPushConstants(buf, vklay, shader_mask, 0, sizeof(stdPush), &stdPush );
                    break;
                case PushConfigType::Custom:
                    {
                        const PushBufferObjectInfo* pbo = pipe->push_buffer();
                        if(pbo){
                            BufferData      bd  = pbo->get(r);
                            if(bd.data && bd.size)
                                vkCmdPushConstants(buf, vklay, shader_mask, 0, bd.size, bd.data);
                        }
                    }
                    break;
                case PushConfigType::None:
                default:
                    // no push constant desired... which is fine.
                    break;
                }
                
                //  =================================================
                //      VERTEX BUFFERS
                
                //std::vector<VkBuffer>       buffers;
                //std::vector<VkDeviceSize>   offsets;
                
                for(const VertexBufferObjectInfo* vbo : pipe->vertex_buffers()){
                    if(!vbo) [[unlikely]]
                        continue;
                    ViBuffer*   buffer  = nullptr;
                    Tristate    update;

                    DataActivity    da  = vbo->data_activity();
                    bool            check   = false;
                    bool            fast    = false;
                    bool            bnew    = false;
                    switch(da){
                    case DataActivity::UNSURE:
                        continue;
                    case DataActivity::COMMON:
                        std::tie(buffer, bnew)  = vp -> buffer(vbo->id());
                        break;
                    case DataActivity::STATIC:
                        std::tie(buffer, bnew)  = vo -> buffer(vbo->id());
                        break;
                    case DataActivity::DYNAMIC:
                        std::tie(buffer, bnew)  = vo -> buffer(vbo->id());
                        check   = true;
                        break;
                    case DataActivity::REFRESH:
                        std::tie(buffer, bnew)  = vo -> buffer(vbo->id());
                        check   = true;
                        fast    = true;
                        break;
                    }
                    
                    
                    if(bnew || check){
                        BufferData  bd    = vbo->get(r);
                        if(!bd.data || !bd.size)
                            continue;
                        if(bnew || fast || (check && bd.revision != buffer->rev)){
                            // optimize this ... later
                            buffer -> vq    = std::make_unique<VqBuffer>(*m_viz, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, bd.data, bd.size);
                            buffer -> rev   = bd.revision;
                        }
                    }
                    
                    if(buffer->vq && buffer->vq->buffer()){
                        VkBuffer        vb  = buffer->vq->buffer();
                        VkDeviceSize    zero{};
                        vkCmdBindVertexBuffers(buf, vbo->binding(), 1, &vb, &zero);
                    }
                }
                
                bool    indexed = false;
                size_t  idx_count   = 0;
                
                //  =================================================
                //      INDEX BUFFERS
                for(const IndexBufferObjectInfo* ibo : pipe->index_buffers()){
                    if(!ibo) [[ unlikely ]]
                        continue;
                        
                    if(ibo->index_type() == IndexType::none)[[ unlikely ]]
                        continue;
                    ViBuffer*   buffer  = nullptr;
                    Tristate    update;

                    DataActivity    da  = ibo->data_activity();
                    bool            check   = false;
                    bool            fast    = false;
                    bool            bnew    = false;
                    switch(da){
                    case DataActivity::UNSURE:
                        continue;
                    case DataActivity::COMMON:
                        std::tie(buffer, bnew)  = vp -> buffer(ibo->id());
                        break;
                    case DataActivity::STATIC:
                        std::tie(buffer, bnew)  = vo -> buffer(ibo->id());
                        break;
                    case DataActivity::DYNAMIC:
                        std::tie(buffer, bnew)  = vo -> buffer(ibo->id());
                        check   = true;
                        break;
                    case DataActivity::REFRESH:
                        std::tie(buffer, bnew)  = vo -> buffer(ibo->id());
                        check   = true;
                        fast    = true;
                        break;
                    }
                    
                    
                    if(bnew || check){
                        BufferData  bd    = ibo->get(r);
                        if(!bd.data || !bd.size)
                            continue;
                        if(bnew || fast || (check && bd.revision != buffer->rev)){
                            // optimize this ... later
                            buffer -> vq    = std::make_unique<VqBuffer>(*m_viz, VK_BUFFER_USAGE_INDEX_BUFFER_BIT, bd.data, bd.size);
                            buffer -> rev   = bd.revision;
                        }
                    }
                    
                    if(buffer->vq && buffer->vq->buffer()){
                        VkBuffer        vb  = buffer->vq->buffer();
                        
                        // recover the size... (yeah, short-sighted...)
                        switch(ibo->index_type()){
                        case IndexType::uint32:
                            idx_count   = buffer->vq->size() / sizeof(uint32_t);
                            break;
                        case IndexType::uint16:
                            idx_count   = buffer->vq->size() / sizeof(uint16_t);
                            break;
                        case IndexType::uint8:
                            idx_count   = buffer->vq->size();
                            break;
                        default:
                            break;
                        }
                        vkCmdBindIndexBuffer(buf, vb, 0, (VkIndexType)(ibo->index_type().value()));
                        indexed         = true;
                        break;
                    }                    
                }

                //if(!buffers.empty())
                    //vkCmdBindVertexBuffers(buf, 0, buffers.size(), buffers.data(), offsets.data());
             
                const auto& dc = r->draw();
                if(indexed){
                    vkCmdDrawIndexed(buf, idx_count, 1, 0, 0, 0);
                } else {
                    vkCmdDraw(buf, dc.vertex_count, 1, 0, 0);
                }
            }
        }        
        
        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////


        RGBA4F Viewer::clear_color() const
        {
            return m_viz -> clear_color();
        }

        VkCommandBuffer  Viewer::command_buffer() const
        {
            return m_viz->frame().commandBuffer;
        }

        VkCommandPool  Viewer::command_pool() const 
        { 
            return m_viz->m_thread->graphic; 
        }
        
        VkQueue  Viewer::compute_queue(uint32_t i) const
        {
            return m_viz->compute_queue(i);
        }
        
        uint32_t  Viewer::compute_queue_count() const
        {
            return m_viz->compute_queue_count();
        }
        
        uint32_t  Viewer::compute_queue_family() const
        {
            return m_viz->compute_queue_family();
        }

        VkDescriptorPool    Viewer::descriptor_pool() const 
        { 
            return m_viz->m_thread->descriptors; 
        }
        
        VkDevice  Viewer::device() const 
        { 
            return m_viz->device(); 
        }

        std::string_view    Viewer::gpu_name() const
        {
            return m_viz -> gpu_name();
        }

        VkPhysicalDeviceType    Viewer::gpu_type() const
        {
            return m_viz -> gpu_type();
        }

        
        VkQueue     Viewer::graphic_queue(uint32_t i) const
        {
            return m_viz->graphic_queue(i);
        }
        
        uint32_t    Viewer::graphic_queue_count() const
        {
            return m_viz->graphic_queue_count();
        }
        
        uint32_t    Viewer::graphic_queue_family() const
        {
            return m_viz->graphic_queue_family();
        }
        
        VkDevice    Viewer::logical() const 
        { 
            return m_viz->device(); 
        }


        uint32_t    Viewer::max_memory_allocation_count() const  
        { 
            return m_viz->max_memory_allocation_count(); 
        }
        
        uint32_t    Viewer::max_push_constants_size() const 
        { 
            return m_viz->max_push_constants_size(); 
        }
        
        uint32_t    Viewer::max_viewports() const 
        { 
            return m_viz->max_viewports(); 
        }

        VkPhysicalDevice    Viewer::physical() const 
        { 
            return m_viz->physical(); 
        }

        tachyon::PresentMode  Viewer::present_mode() const
        {
            return m_viz->present_mode();
        }

        const std::set<tachyon::PresentMode>&     Viewer::present_modes_available() const
        {
            return m_viz->present_modes_available();
        }

        VkQueue      Viewer::present_queue(uint32_t i) const
        {
            return m_viz->present_queue(i);
        }
        
        uint32_t     Viewer::present_queue_count() const
        {
            return m_viz->present_queue_count();
        }
        
        uint32_t     Viewer::present_queue_family() const
        {
            return m_viz->present_queue_family();
        }

        VkRenderPass Viewer::render_pass() const
        {
            return m_viz->m_renderPass;
        }


        void        Viewer::set_clear_color(const RGBA4F&i)
        {
            m_viz->set_clear_color(i);
        }

        void        Viewer::set_present_mode(PresentMode pm)
        {
            m_viz -> set_present_mode(pm);
        }


        bool                Viewer::supports(VkFormat fmt) const
        {
            return m_viz -> supports_surface(fmt);
        }
        
        bool                Viewer::supports(PresentMode pm) const
        {
            return m_viz->supports_present(pm);
        }

        VkSurfaceKHR        Viewer::surface() const 
        { 
            return m_viz->surface(); 
        }

        VkFormat            Viewer::surface_format() const
        {
            return m_viz->surface_format();
        }

        VkColorSpaceKHR  Viewer::surface_color_space() const 
        { 
            return m_viz->surface_color_space(); 
        }

        VkRect2D    Viewer::swap_def_scissor() const
        {
            return m_viz->m_swapchain->def_scissor();
        }
        
        VkViewport  Viewer::swap_def_viewport() const
        {
            return m_viz->m_swapchain->def_viewport();
        }

        uint32_t    Viewer::swap_image_count() const
        {
            return m_viz->m_swapchain->imageCount;
        }

        uint32_t    Viewer::swap_height() const
        {
            return m_viz->m_swapchain->height();
        }

        uint32_t    Viewer::swap_min_image_count() const
        {
            return m_viz->m_swapchain->minImageCount;
        }

        uint32_t    Viewer::swap_width() const
        {
            return m_viz->m_swapchain->width();
        }
        
        VkQueue   Viewer::video_decode_queue(uint32_t i) const
        {
            return m_viz->video_decode_queue(i);
        }
        
        uint32_t  Viewer::video_decode_queue_count() const
        {
            return m_viz->video_decode_queue_count();
        }
        
        uint32_t  Viewer::video_decode_queue_family() const
        {
            return m_viz->video_decode_queue_family();
        }

        VkQueue   Viewer::video_encode_queue(uint32_t i) const
        {
            return m_viz->video_encode_queue(i);
        }
        
        uint32_t  Viewer::video_encode_queue_count() const
        {
            return m_viz->video_encode_queue_count();
        }

        uint32_t  Viewer::video_encode_queue_family() const
        {
            return m_viz->video_encode_queue_family();
        }

        
        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////


        ViBuffer::ViBuffer()
        {
        }
        
        ViBuffer::~ViBuffer()
        {
        }
        
        ////////////////////////////////////////////////////////////////////////////////

        ViBufferMap::ViBufferMap()
        {
        }
        
        ViBufferMap::~ViBufferMap()
        {
            for(auto& b : buffers){
                if(b.second)
                    delete b.second;
            }
            buffers.clear();
        }

        ////////////////////////////////////////////////////////////////////////////////

        ViFrame::ViFrame(Visualizer* viz_) : viz(viz_)
        {
            try {
                VqCommandBufferAllocateInfo allocInfo;
                allocInfo.commandPool           = viz->m_thread->graphic;
                allocInfo.level                 = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
                allocInfo.commandBufferCount    = 1;
                if (vkAllocateCommandBuffers(viz->device(), &allocInfo, &commandBuffer) != VK_SUCCESS) 
                    throw VqException("Failed to allocate command buffers!");

                VqFenceCreateInfo   fci;
                fci.flags = VK_FENCE_CREATE_SIGNALED_BIT;
                if(vkCreateFence(viz->device(), &fci, nullptr,  &fence) != VK_SUCCESS)
                    throw VqException("Unable to create fence!");

                VqSemaphoreCreateInfo   info;
                if(vkCreateSemaphore(viz->device(), &info, nullptr, &imageAvailable) != VK_SUCCESS)
                    throw VqException("Unable to create semaphore!");
                if(vkCreateSemaphore(viz->device(), &info, nullptr, &renderFinished) != VK_SUCCESS)
                    throw VqException("Unable to create semaphore!");
            } 
            catch(VqException& ex)
            {
                dtor();
                throw;
            }
        }
        
        ViFrame::~ViFrame()
        {
            dtor();
        }
        
        void    ViFrame::dtor()
        {
            if(viz){
                if(commandBuffer && viz->m_thread->graphic){
                    vkFreeCommandBuffers(viz->device(), viz->m_thread->graphic, 1, &commandBuffer);
                    commandBuffer   = nullptr;
                }
                
                if(imageAvailable){
                    vkDestroySemaphore(viz->device(), imageAvailable, nullptr);
                    imageAvailable  = nullptr;
                }
                
                if(renderFinished){
                    vkDestroySemaphore(viz->device(), renderFinished, nullptr);
                    renderFinished  = nullptr;
                }
                
                if(fence){
                    vkDestroyFence(viz->device(), fence, nullptr);
                    fence   = nullptr;
                }
                
                viz = nullptr;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////

        ViObject::ViObject()
        {
        }
        
        ViObject::~ViObject()
        {
        }

        ////////////////////////////////////////////////////////////////////////////////

        ViPipeline::ViPipeline()
        {
        }
        
        ViPipeline::~ViPipeline()
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////

        ViSwapchain::ViSwapchain(Visualizer* viz_) : viz(viz_)
        {
            try {
                if(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(viz->physical(), viz->surface(), &capabilities) != VK_SUCCESS)
                    throw VqException("Unable to get surface capabilities");
                if (capabilities.currentExtent.width != std::numeric_limits<uint32_t>::max()) {
                    extents = capabilities.currentExtent;
                } else {
                    int w, h;
                    glfwGetFramebufferSize(viz->_window(), &w, &h);
                    extents = {};
                    extents.width       = std::clamp((uint32_t) w, capabilities.minImageExtent.width, capabilities.maxImageExtent.width);
                    extents.height      = std::clamp((uint32_t) h, capabilities.minImageExtent.height, capabilities.maxImageExtent.height);
                }

                #if 0
                int w, h;
                glfwGetFramebufferSize(viz._window(), &w, &h);
                vqInfo << "init dymamic stuff\n"<<
                "Frame itself is [" << w << 'x' << h << "] vs\n" <<
                "Image extents is " << ds.extents << '\n' <<
                "Cur is " << capabilities.currentExtent << '\n' <<
                "Min is " << capabilities.minImageExtent << '\n' <<
                "Max is " << capabilities.maxImageExtent
                ;
                #endif

                minImageCount               = capabilities.minImageCount;
                if(minImageCount < 2)
                    minImageCount   = 2;
                imageCount                  = minImageCount + 1;
                if (capabilities.maxImageCount > 0 && imageCount > capabilities.maxImageCount) {
                    imageCount = capabilities.maxImageCount;
                }

                VqSwapchainCreateInfoKHR    swapInfo;
                swapInfo.surface          = viz->surface();
                swapInfo.minImageCount    = imageCount;
                swapInfo.imageFormat      = viz->surface_format();
                swapInfo.imageColorSpace  = viz->surface_color_space();
                swapInfo.imageExtent      = extents;
                swapInfo.imageArrayLayers = 1;    // we're not steroscopic (YET)  <-- OCULUS HERE
                swapInfo.imageUsage       = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
                
                uint32_t queueFamilyIndices[] = {viz->graphic_queue_family(), viz->present_queue_family()};
                if (viz->graphic_queue_family() != viz->present_queue_family()) {
                    swapInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
                    swapInfo.queueFamilyIndexCount = 2;
                    swapInfo.pQueueFamilyIndices = queueFamilyIndices;
                } else {
                    swapInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
                    swapInfo.queueFamilyIndexCount = 0; // Optional
                    swapInfo.pQueueFamilyIndices = nullptr; // Optional
                }        
                swapInfo.preTransform     = capabilities.currentTransform;
                swapInfo.compositeAlpha   = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
                swapInfo.presentMode      = (VkPresentModeKHR) viz->present_mode().value();
                swapInfo.clipped          = VK_TRUE;
                
                    // TEMPORARY UNTIL WE GET THE NEW ONE
                if(viz->m_swapchain){
                    swapInfo.oldSwapchain = viz->m_swapchain->swapchain;
                } else {
                    swapInfo.oldSwapchain = nullptr;
                }
                    
                if (vkCreateSwapchainKHR(viz->device(), &swapInfo, nullptr, &swapchain) != VK_SUCCESS)
                    throw VqException("Failed to create the SWAP chain!");

                if(vkGetSwapchainImagesKHR(viz->device(), swapchain, &imageCount, nullptr) != VK_SUCCESS)
                    throw VqException("Unable to get image count.");
                images.resize(imageCount, nullptr);
                if(vkGetSwapchainImagesKHR(viz->device(), swapchain, &imageCount, images.data()) != VK_SUCCESS)
                    throw VqException("Unable to get images!");
                                
                imageViews.resize(imageCount, nullptr);

                VqImageViewCreateInfo       imageViewInfo;
                imageViewInfo.viewType     = VK_IMAGE_VIEW_TYPE_2D;
                imageViewInfo.format       = viz->surface_format();
                imageViewInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
                imageViewInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
                imageViewInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
                imageViewInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
                imageViewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
                imageViewInfo.subresourceRange.baseMipLevel = 0;
                imageViewInfo.subresourceRange.levelCount = 1;
                imageViewInfo.subresourceRange.baseArrayLayer = 0;
                imageViewInfo.subresourceRange.layerCount = 1;
                
                for(size_t i=0; i<imageCount; ++i){
                    imageViewInfo.image        = images[i];
                    if(vkCreateImageView(viz->device(), &imageViewInfo, nullptr, &imageViews[i]) != VK_SUCCESS) 
                        throw VqException("Failed to create one of the Swap Image Viewers!");
                }                
                
                frameBuffers.resize(imageCount, nullptr);

                VqFramebufferCreateInfo   frameBufferInfo;
                frameBufferInfo.renderPass       = viz->m_renderPass;
                frameBufferInfo.attachmentCount  = 1;
                frameBufferInfo.width            = extents.width;
                frameBufferInfo.height           = extents.height;
                frameBufferInfo.layers           = 1;

                for(size_t i=0;i<imageCount;++i){
                    frameBufferInfo.pAttachments = &imageViews[i];
                    if (vkCreateFramebuffer(viz->device(), &frameBufferInfo, nullptr, &frameBuffers[i]) != VK_SUCCESS) 
                        throw VqException("Failed to create framebuffer!");
                }
            }
            catch(VqException& ex){
                dtor();
                throw;
            }
        }
        
        ViSwapchain::~ViSwapchain()
        {
            dtor();
        }
        
        void    ViSwapchain::dtor()
        {
            if(viz){
                for(size_t i=0;i<imageCount;++i){
                    if((i < frameBuffers.size()) && frameBuffers[i])
                        vkDestroyFramebuffer(viz->device(), frameBuffers[i], nullptr);
                    if((i < imageViews.size()) && imageViews[i])
                        vkDestroyImageView(viz->device(), imageViews[i], nullptr);
                }
                frameBuffers.clear();
                imageViews.clear();
                images.clear();
                if(swapchain){
                    vkDestroySwapchainKHR(viz->device(), swapchain, nullptr);
                    swapchain  = nullptr;
                }
                viz = nullptr;
            }
        }

        VkRect2D  ViSwapchain::def_scissor() const
        {
            VkRect2D    ret{};
            ret.offset  = { 0, 0 };
            ret.extent  = extents;
            return ret;
        }
        
        VkViewport  ViSwapchain::def_viewport() const
        {
            VkViewport  ret{};
            ret.x = 0.0f;
            ret.y = 0.0f;
            ret.width = (float) extents.width;
            ret.height = (float) extents.height;
            ret.minDepth = 0.0f;
            ret.maxDepth = 1.0f;
            return ret;
        }
        
        uint32_t  ViSwapchain::width() const 
        { 
            return extents.width; 
        }
        
        uint32_t  ViSwapchain::height() const 
        { 
            return extents.height; 
        }

        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////

        ViThread::ViThread(Visualizer* viz_) : viz(viz_)
        {
            try {
                std::vector<VkDescriptorPoolSize> descriptorPoolSizes =
                {
                    { VK_DESCRIPTOR_TYPE_SAMPLER, viz->m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, viz->m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE, viz->m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_STORAGE_IMAGE, viz->m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER, viz->m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER, viz->m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, viz->m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, viz->m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC, viz->m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC, viz->m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT, viz->m_descriptorCount }
                };
                VqDescriptorPoolCreateInfo descriptorPoolInfo;
                descriptorPoolInfo.flags         = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;
                descriptorPoolInfo.maxSets       = viz->m_descriptorCount * descriptorPoolSizes.size();
                descriptorPoolInfo.poolSizeCount = (uint32_t) descriptorPoolSizes.size();
                descriptorPoolInfo.pPoolSizes    = descriptorPoolSizes.data();
                if(vkCreateDescriptorPool(viz->device(), &descriptorPoolInfo, nullptr, &descriptors) != VK_SUCCESS)
                    throw VqException("Unable to allocate the descriptor pool!");

                VqCommandPoolCreateInfo poolInfo;
                poolInfo.flags              = viz->m_cmdPoolCreateFlags;
                
                if(viz->graphic_queue_valid()){
                    poolInfo.queueFamilyIndex   = viz->graphic_queue_family();
                    if (vkCreateCommandPool(viz->device(), &poolInfo, nullptr, &graphic) != VK_SUCCESS) 
                        throw VqException("Failed to create a graphic command pool!");
                }
                if(viz->compute_queue_valid()){
                    poolInfo.queueFamilyIndex   = viz->compute_queue_family();
                    if (vkCreateCommandPool(viz->device(), &poolInfo, nullptr, &compute) != VK_SUCCESS) 
                        throw VqException("Failed to create a compute command pool!");
                }
            }
            catch(VqException& ex)
            {
                dtor();
                throw;
            }
        }
        
        ViThread::~ViThread()
        {
            dtor();
        }
        
        void    ViThread::dtor()
        {
            if(viz){
                if(descriptors){
                    vkDestroyDescriptorPool(viz->device(), descriptors, nullptr);
                    descriptors = nullptr;
                }
                if(graphic){
                    vkDestroyCommandPool(viz->device(), graphic, nullptr);
                    graphic = nullptr;
                }
                if(compute){
                    vkDestroyCommandPool(viz->device(), compute, nullptr);
                    compute = nullptr;
                }
                viz  = nullptr;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////
        

        Visualizer::Visualizer(const ViewerCreateInfo& vci, Viewer *w)
        {
            m_viewer        = w;
            try {
                init_visualizer(vci, w->window());
                _ctor(vci);
            }
            catch(std::error_code ec)
            {
                _dtor();
                throw;
            }
            catch(VqException& ex)
            {
                _dtor();
                throw;
            }
        }

        Visualizer::~Visualizer()
        {
            _dtor();
        }



        void Visualizer::_ctor(const ViewerCreateInfo& vci)
        {

            


            //  ================================
            //  DESCRIPTOR & COMMAND POOL

            m_descriptorCount   = std::max(MIN_DESCRIPTOR_COUNT, vci.descriptors);
            m_thread            = std::make_unique<ViThread>(this);
            
            //  ================================
            //  RENDER PASS

            VkAttachmentDescription colorAttachment{};
            colorAttachment.format          = m_surfaceFormat;
            colorAttachment.samples         = VK_SAMPLE_COUNT_1_BIT;
            colorAttachment.loadOp          = VK_ATTACHMENT_LOAD_OP_CLEAR;
            colorAttachment.storeOp         = VK_ATTACHMENT_STORE_OP_STORE;        
            colorAttachment.stencilLoadOp   = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
            colorAttachment.stencilStoreOp  = VK_ATTACHMENT_STORE_OP_DONT_CARE;
            colorAttachment.initialLayout   = VK_IMAGE_LAYOUT_UNDEFINED;
            colorAttachment.finalLayout     = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
            
            VkAttachmentReference colorAttachmentRef{};
            colorAttachmentRef.attachment = 0;
            colorAttachmentRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

            VkSubpassDescription subpass{};
            subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;        

            subpass.colorAttachmentCount = 1;
            subpass.pColorAttachments = &colorAttachmentRef;
            
            VqRenderPassCreateInfo renderPassInfo;
            renderPassInfo.attachmentCount = 1;
            renderPassInfo.pAttachments = &colorAttachment;
            renderPassInfo.subpassCount = 1;
            renderPassInfo.pSubpasses = &subpass;

            if (vkCreateRenderPass(m_device, &renderPassInfo, nullptr, &m_renderPass) != VK_SUCCESS) 
                throw VqException("Unable to create the render pass!");

            //  ================================
            //  PRESENT MODE

            m_presentMode               = m_presentModes.contains(vci.pmode) ? vci.pmode : PresentMode{ PresentMode::Fifo };
                
            //  ================================
            //  FRAMES
            
            for(auto& f : m_frames)
                f   = new ViFrame(this);

            
            m_swapchain     = new ViSwapchain(this);

            //  ================================
            //  IMGUI (optional)
                
            
            //  ================================
            //  OLDER STUFF

            
            
            //builder = std::thread([this](){
                //this->run();
            //});
        }
        

        void Visualizer::_dtor()
        {
            if(!m_device)
                return ;
            vkDeviceWaitIdle(m_device);

            for(auto& i : objects){
                if(i.second)
                    delete i.second;
            }
            objects.clear();

            for(auto& i : pipelines){
                if(i.second)
                    delete i.second;
            }
            pipelines.clear();
            
            if(m_swapchain){
                delete m_swapchain;
                m_swapchain = nullptr;
            }
            
            for(auto& f : m_frames){
                delete f;
                f   = nullptr;
            }
            
            if(m_renderPass){
                vkDestroyRenderPass(m_device, m_renderPass, nullptr);
                m_renderPass = nullptr;
            }
            
            m_thread                    = {};
            
            
            kill_visualizer();
            
            m_viewer                    = nullptr;
        }

        bool Visualizer::check_rebuild(bool force)
        {
            if(force){
                m_rebuildSwap   = false;
            } else {
                force       = m_rebuildSwap.exchange(false);
                if(!force)
                    return false;
            }
        
            vkDeviceWaitIdle(m_device);
            ViSwapchain*    newchain    = new ViSwapchain(this);
            std::swap(newchain, m_swapchain);
            delete newchain;
            return true;
        }

        bool  Visualizer::graphic_draw()
        {
            ViFrame&    f   = frame();
            vkWaitForFences(m_device, 1, &f.fence, VK_TRUE, UINT64_MAX);

            uint32_t imageIndex = 0;
            VkResult res    = vkAcquireNextImageKHR(m_device, m_swapchain->swapchain, UINT64_MAX, f.imageAvailable, VK_NULL_HANDLE, &imageIndex);
            bool    force   = false;
            switch(res){
            case VK_SUCCESS:
                break;
            case VK_SUBOPTIMAL_KHR:
            case VK_ERROR_OUT_OF_DATE_KHR:
                force       = true;
                break;
            default:
                vqError << "Unable to acquire next image!";
                return false;
            }
            
            if(check_rebuild(force))
                return true;

            vkResetFences(m_device, 1, &f.fence);
            vkResetCommandBuffer(f.commandBuffer, 0);
            
            if(!graphic_record(f.commandBuffer, imageIndex))
                return false;
            
            VqSubmitInfo submitInfo;

            VkSemaphore waitSemaphores[] = { f.imageAvailable };
            VkPipelineStageFlags waitStages[] = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
            submitInfo.waitSemaphoreCount = 1;
            submitInfo.pWaitSemaphores      = waitSemaphores;
            submitInfo.pWaitDstStageMask    = waitStages;
            submitInfo.commandBufferCount   = 1;
            submitInfo.pCommandBuffers      = &f.commandBuffer;

            VkSemaphore signalSemaphores[]  = {f.renderFinished};
            submitInfo.signalSemaphoreCount = 1;
            submitInfo.pSignalSemaphores    = signalSemaphores;

            if (vkQueueSubmit(m_graphic[0], 1, &submitInfo, f.fence) != VK_SUCCESS) {
                vqError << "Failed to submit draw command buffer!";
                return false;
            }
                
            VqPresentInfoKHR presentInfo;

            presentInfo.waitSemaphoreCount = 1;
            presentInfo.pWaitSemaphores = signalSemaphores;
            presentInfo.swapchainCount = 1;
            presentInfo.pSwapchains = &m_swapchain->swapchain;
            presentInfo.pImageIndices = &imageIndex;
            presentInfo.pResults = nullptr; // Optional
            vkQueuePresentKHR(m_present[0], &presentInfo);
            
            ++m_tick;
            return true;
        }
        
        bool  Visualizer::graphic_record(VkCommandBuffer cmd, uint32_t imgIndex)
        {
            VqCommandBufferBeginInfo beginInfo;
            beginInfo.flags = 0; // Optional
            beginInfo.pInheritanceInfo = nullptr; // Optional

            if (vkBeginCommandBuffer(cmd, &beginInfo) != VK_SUCCESS) {
                vqError << "Failed to begin recording command buffer!";
                return false;
            }

            VqRenderPassBeginInfo renderPassInfo;
            renderPassInfo.renderPass = m_renderPass;
            renderPassInfo.framebuffer = m_swapchain->frameBuffers[imgIndex];
            renderPassInfo.renderArea.offset = {0, 0};
            renderPassInfo.renderArea.extent = m_swapchain->extents;

            renderPassInfo.clearValueCount = 1;
            VkClearValue                cv  = m_clearValue;
            renderPassInfo.pClearValues = &cv;
            vkCmdBeginRenderPass(cmd, &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);
        
            m_viewer->draw_vulqan(cmd);
            if(m_viewer->m_imgui)
                ImGui_ImplVulkan_RenderDrawData(ImGui::GetDrawData(), cmd, nullptr);

            vkCmdEndRenderPass(cmd);

            if (vkEndCommandBuffer(cmd) != VK_SUCCESS) {
                vqError << "Failed to record command buffer!";
                return false;
            }
            return true;
        }

        void  Visualizer::run()
        {
            //using namespace std::chrono_literals;
            //while(!terminating){
                //std::this_thread::sleep_for(1ms);
            //}
        }


        std::pair<ViPipeline*,bool>    Visualizer::pipeline(uint64_t i)
        {
            auto j = pipelines.find(i);
            if(j!=pipelines.end())
                return {j->second,false};
            ViPipeline* p   = new ViPipeline;
            pipelines[i]    = p;
            return {p, true};
        }
        
        std::pair<ViObject*,bool>    Visualizer::object(uint64_t i)
        {
            auto j = objects.find(i);
            if(j!=objects.end())
                return {j->second,false};
            ViObject* p   = new ViObject;
            objects[i]    = p;
            return {p, true};
        }


        //  ----------------------------------------------------------------------------
        //  ----------------------------------------------------------------------------



        
        YQ_INVOKE(
            writer<Viewer>();
        )
        
    }
}

