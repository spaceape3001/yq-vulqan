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
#include "Shader.hpp"
#include "Viewer.hpp"
#include "Visualizer.hpp"

#include <basic/CollectionUtils.hpp>
#include <basic/Logging.hpp>
#include <basic/Safety.hpp>
#include <basic/TextUtils.hpp>
#include <basic/meta/ObjectInfoWriter.hpp>


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
#include <engine/vulqan/VqException.hpp>
#include <engine/vulqan/VqLogging.hpp>
#include <engine/vulqan/VqPipeline.hpp>
#include <engine/vulqan/VqStructs.hpp>
#include <engine/vulqan/VqUtils.hpp>

#include <math/Size2.hpp>
#include <math/Vector2.hpp>

#include <algorithm>
#include <cassert>

#include <GLFW/glfw3.h>

#include <imgui.h>
#include <backends/imgui_impl_vulkan.h>
#include <backends/imgui_impl_glfw.h>

YQ_OBJECT_IMPLEMENT(yq::engine::Viewer)


namespace yq {
    namespace engine {
        WindowInfo::WindowInfo(std::string_view kname, ObjectInfo& base, const std::source_location& sl) :
            ObjectInfo(kname, base, sl)
        {
        }

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
        
        void  Viewer::callback_drop(GLFWwindow* window, int count, const char** paths)
        {
        }
        
        void  Viewer::callback_framebuffer_size(GLFWwindow* window, int width, int height)
        {
            Viewer    *v  = (Viewer*) glfwGetWindowUserPointer(window);
            if(v){
                v -> m_viz -> m_rebuildSwap    = true;
                if(v) [[likely]]
                    v->window_resized();
            }
            yInfo() << "Frame size changed!";
        }
        
        void  Viewer::callback_joystick(int jid, int event)
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

        void  Viewer::callback_window_close(GLFWwindow* window)
        {
            yInfo() << "Window close requested";
        }
        
        void  Viewer::callback_window_focus(GLFWwindow* window, int focused)
        {
            ImGui_ImplGlfw_WindowFocusCallback(window, focused);
            yInfo() << "Window focus changed!";
        }
        
        void  Viewer::callback_window_iconify(GLFWwindow* window, int iconified)
        {
            yInfo() << "Viewer iconified";
        }
        
        void  Viewer::callback_window_maximize(GLFWwindow* window, int maximized)
        {
            yInfo() << "Viewer maximized";
        }
        
        void  Viewer::callback_window_position(GLFWwindow* window, int xpos, int ypos)
        {
            yInfo() << "Viewer moved!";
        }
        
        void  Viewer::callback_window_refresh(GLFWwindow* window)
        {
            yInfo() << "Viewer refresh!"; // (ignoring)
        }
        
        void  Viewer::callback_window_scale(GLFWwindow* window, float xscale, float yscale)
        {
            yInfo() << "Viewer rescaled!";
        }
        
        void  Viewer::callback_window_size(GLFWwindow* window, int x, int y)
        {
            Viewer    *v  = (Viewer*) glfwGetWindowUserPointer(window);
            if(v){
                v -> m_viz -> m_rebuildSwap    = true;
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
                
                glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
                glfwWindowHint(GLFW_FLOATING, vci.floating ? GLFW_TRUE : GLFW_FALSE);
                glfwWindowHint(GLFW_DECORATED, vci.decorated ? GLFW_TRUE : GLFW_FALSE);
                glfwWindowHint(GLFW_RESIZABLE, vci.resizable ? GLFW_TRUE : GLFW_FALSE);
                
                int wx  = std::max(1,vci.size.width());
                int wy  = std::max(1,vci.size.height());

                m_window = glfwCreateWindow(wx, wy, vci.title, vci.monitor.monitor(), nullptr);
                if(!m_window)
                    throw VqException("Unable to create GLFW m_window");
                
                //  Register pointer & callbacks
                glfwSetWindowUserPointer(m_window, this);
                
                glfwSetCharCallback(m_window, callback_character);
                glfwSetCursorEnterCallback(m_window, callback_cursor_enter);
                glfwSetCursorPosCallback(m_window, callback_cursor_position);
                glfwSetDropCallback(m_window, callback_drop);
                glfwSetFramebufferSizeCallback(m_window, callback_framebuffer_size);
                glfwSetKeyCallback(m_window, callback_key);
                [[maybe_unused]] static auto fn2 = glfwSetJoystickCallback( callback_joystick );
                [[maybe_unused]] static auto fn1 = glfwSetMonitorCallback( callback_monitor);
                glfwSetMouseButtonCallback(m_window, callback_mouse_button);
                glfwSetScrollCallback(m_window, callback_scroll);
                glfwSetWindowCloseCallback(m_window, callback_window_close);
                glfwSetWindowContentScaleCallback(m_window, callback_window_scale);
                glfwSetWindowFocusCallback(m_window, callback_window_focus);
                glfwSetWindowIconifyCallback(m_window, callback_window_iconify);
                glfwSetWindowMaximizeCallback(m_window, callback_window_maximize);
                glfwSetWindowPosCallback(m_window, callback_window_position);
                glfwSetWindowRefreshCallback(m_window, callback_window_refresh);
                glfwSetWindowSizeCallback(m_window, callback_window_size);

                m_viz   = std::make_unique<Visualizer>(vci,this);
                
                if(vci.imgui){
                    m_imgui = ImGui::CreateContext();

                    ImGui_ImplVulkan_InitInfo vii{};
                    
                    vii.Instance        = Application::vulkan();
                    vii.PhysicalDevice  = m_viz->m_physical;
                    vii.Device          = m_viz->m_device;
                    vii.Queue           = m_viz->m_graphic[0];
                    vii.QueueFamily     = m_viz->m_graphic.family;
                    vii.MinImageCount   = m_viz->m_swapchain->minImageCount;
                    vii.ImageCount      = m_viz->m_swapchain->imageCount;
                    vii.DescriptorPool  = m_viz->m_thread->descriptors;
                    
                    ImGui::SetCurrentContext(m_imgui);
                    ImGui_ImplGlfw_InitForVulkan(m_window, false);
                    ImGui_ImplVulkan_Init(&vii, m_viz->m_renderPass);
                    
                    //  Uploading fonts....
                    
                    VkCommandBuffer cbuffer = m_viz->m_frames[0]->commandBuffer;

                    vkResetCommandPool(m_viz->m_device, m_viz->m_thread->graphic, 0);
                    VqCommandBufferBeginInfo begin_info;
                    begin_info.flags |= VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
                    vkBeginCommandBuffer(cbuffer, &begin_info);

                    ImGui_ImplVulkan_CreateFontsTexture(cbuffer);

                    VqSubmitInfo end_info;
                    end_info.commandBufferCount = 1;
                    end_info.pCommandBuffers = &cbuffer;
                    vkEndCommandBuffer(cbuffer);
                    vkQueueSubmit(m_viz->m_graphic[0], 1, &end_info, VK_NULL_HANDLE);
                    vkDeviceWaitIdle(m_viz->m_device);
                    ImGui_ImplVulkan_DestroyFontUploadObjects();
                }


                set_clear_color(vci.clear);
                m_title     = vci.title;
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
            if(m_window){
                glfwDestroyWindow(m_window);
                m_window    = nullptr;
            }
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

        void    Viewer::draw_vulqan(VkCommandBuffer cmdbuf)
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


        void Viewer::attention()
        {
            if(m_viz->m_window)
                glfwRequestWindowAttention(m_viz->m_window);
        }

        RGBA4F Viewer::clear_color() const
        {
            VkClearValue    cv  = m_viz->m_clearValue;
            return { 
                cv.color.float32[0], cv.color.float32[1], 
                cv.color.float32[2], cv.color.float32[3] 
            };
        }

        void Viewer::close()
        {
            if(m_viz->m_window)
                glfwSetWindowShouldClose(m_viz->m_window, GLFW_TRUE);
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
            return m_viz->m_compute[i];
        }
        
        uint32_t  Viewer::compute_queue_count() const
        {
            return (uint32_t) m_viz->m_compute.queues.size();
        }
        
        uint32_t  Viewer::compute_queue_family() const
        {
            return m_viz->m_compute.family;
        }

        VkDescriptorPool    Viewer::descriptor_pool() const 
        { 
            return m_viz->m_thread->descriptors; 
        }
        
        VkDevice  Viewer::device() const 
        { 
            return m_viz->m_device; 
        }

        void Viewer::focus()
        {
            if(m_viz && m_viz->m_window)
                glfwFocusWindow(m_viz->m_window);
        }

        std::string_view    Viewer::gpu_name() const
        {
            return std::string_view(m_viz->m_deviceInfo.deviceName, strnlen(m_viz->m_deviceInfo.deviceName, VK_MAX_PHYSICAL_DEVICE_NAME_SIZE));
        }

        VkPhysicalDeviceType    Viewer::gpu_type() const
        {
            return m_viz->m_deviceInfo.deviceType;
        }

        
        VkQueue     Viewer::graphic_queue(uint32_t i) const
        {
            return m_viz->m_graphic[i];
        }
        
        uint32_t    Viewer::graphic_queue_count() const
        {
            return (uint32_t) m_viz->m_graphic.queues.size();
        }
        
        uint32_t    Viewer::graphic_queue_family() const
        {
            return m_viz->m_graphic.family;
        }


        int  Viewer::height() const
        {
            if(!m_viz->m_window)
                return 0;
        
            int ret;
            glfwGetWindowSize(m_viz->m_window, nullptr, &ret);
            return ret;
        }

        void Viewer::hide()
        {
            if(m_viz->m_window)
                glfwHideWindow(m_viz->m_window);
        }

        void Viewer::iconify()
        {
            if(m_viz->m_window)
                glfwIconifyWindow(m_viz->m_window);
        }

        bool        Viewer::is_decorated() const
        {
            if(!m_viz->m_window)
                return false;
            return glfwGetWindowAttrib(m_viz->m_window, GLFW_DECORATED) != 0;
        }
        
        bool        Viewer::is_focused() const
        {
            if(!m_viz->m_window)
                return false;
            return glfwGetWindowAttrib(m_viz->m_window, GLFW_FOCUSED ) != 0;
        }
        
        bool        Viewer::is_floating() const
        {
            if(!m_viz->m_window)
                return false;
            return glfwGetWindowAttrib(m_viz->m_window, GLFW_FLOATING) != 0;
        }
        
        bool        Viewer::is_fullscreen() const
        {
            if(!m_viz->m_window)
                return false;
            return glfwGetWindowMonitor(m_viz->m_window) != nullptr;
        }
        
        bool        Viewer::is_hovered() const
        {
            if(!m_viz->m_window)
                return false;
            return glfwGetWindowAttrib(m_viz->m_window, GLFW_HOVERED) != 0;
        }
        
        bool        Viewer::is_iconified() const
        {
            if(!m_viz->m_window)
                return false;
            return glfwGetWindowAttrib(m_viz->m_window, GLFW_ICONIFIED) != 0;
        }

        bool        Viewer::is_maximized() const
        {
            if(!m_viz->m_window)
                return false;
            return glfwGetWindowAttrib(m_viz->m_window, GLFW_MAXIMIZED) != 0;
        }
        
        bool        Viewer::is_resizable() const
        {
            if(!m_viz->m_window)
                return false;
            return glfwGetWindowAttrib(m_viz->m_window, GLFW_RESIZABLE) != 0;
        }
        
        bool        Viewer::is_visible() const
        {
            if(!m_viz->m_window)
                return false;
            return glfwGetWindowAttrib(m_viz->m_window, GLFW_VISIBLE) != 0;
        }
        
        VkDevice    Viewer::logical() const 
        { 
            return m_viz->m_device; 
        }


        uint32_t    Viewer::max_memory_allocation_count() const  
        { 
            return m_viz->m_deviceInfo.limits.maxMemoryAllocationCount; 
        }
        
        uint32_t    Viewer::max_push_constants_size() const 
        { 
            return m_viz->m_deviceInfo.limits.maxPushConstantsSize; 
        }
        
        uint32_t    Viewer::max_viewports() const 
        { 
            return m_viz->m_deviceInfo.limits.maxViewports; 
        }

        void        Viewer::maximize()
        {
            if(m_viz->m_window)
                glfwMaximizeWindow(m_viz->m_window);
        }

        VqMonitor   Viewer::monitor() const
        {
            if(m_viz->m_window)
                return VqMonitor(glfwGetWindowMonitor(m_viz->m_window));
            return VqMonitor();
        }

        VkPhysicalDevice    Viewer::physical() const 
        { 
            return m_viz->m_physical; 
        }

        Vector2I    Viewer::position() const
        {
            if(!m_viz->m_window)
                return {};
            Vector2I   ret;
            glfwGetWindowPos(m_viz->m_window, &ret.x, &ret.y);
            return ret;
        }

        PresentMode  Viewer::present_mode() const
        {
            return m_viz->m_presentMode;
        }

        const std::set<PresentMode>&     Viewer::present_modes_available() const
        {
            return m_viz->m_presentModes;
        }

        VkQueue      Viewer::present_queue(uint32_t i) const
        {
            return m_viz->m_present[i];
        }
        
        uint32_t     Viewer::present_queue_count() const
        {
            return (uint32_t) m_viz->m_present.queues.size();
        }
        
        uint32_t     Viewer::present_queue_family() const
        {
            return m_viz->m_present.family;
        }

        VkRenderPass Viewer::render_pass() const
        {
            return m_viz->m_renderPass;
        }

        void        Viewer::restore()
        {
            if(m_viz->m_window)
                glfwRestoreWindow(m_viz->m_window);
        }

        void        Viewer::set_clear_color(const RGBA4F&i)
        {
            m_viz->m_clearValue = VkClearValue{{{ i.red, i.green, i.blue, i.alpha }}};
        }

        void        Viewer::set_position(const Vector2I& pos)
        {
            set_position(pos.x, pos.y);
        }

        void        Viewer::set_present_mode(PresentMode pm)
        {
            if(m_viz->m_presentModes.contains(pm) && (pm != m_viz->m_presentMode)){
                m_viz->m_presentMode    = pm;
                m_viz->m_rebuildSwap    = true;
            }
        }
        
        void        Viewer::set_position(int x, int y)
        {
            if(m_viz->m_window){
                glfwSetWindowPos(m_viz->m_window, x, y);
            }
        }

        void        Viewer::set_size(const Size2I& sz)
        {
            set_size(sz.x, sz.y);
        }

        void        Viewer::set_size(int w, int h)
        {
            if(m_viz->m_window){
                glfwSetWindowSize(m_viz->m_window, std::max(1, w), std::max(1, h));
            }
        }

        void        Viewer::set_title(const char*z)
        {
            if(m_viz->m_window && z){
                glfwSetWindowTitle(m_viz->m_window, z);
                m_title = z;
            }
        }

        void        Viewer::set_title(const std::string&z)
        {
            set_title(z.c_str());
        }

        bool        Viewer::should_close() const
        {
            if(!m_viz->m_window) 
                return true;
            return glfwWindowShouldClose(m_viz->m_window);
        }

        void        Viewer::show()
        {
            if(m_viz->m_window)
                glfwShowWindow(m_viz->m_window);
        }

        Size2I      Viewer::size() const
        {
            if(!m_viz->m_window)
                return {};
            Size2I  ret;
            glfwGetWindowSize(m_viz->m_window, &ret.x, &ret.y);
            return ret;
        }

        bool                Viewer::supports(VkFormat fmt) const
        {
            for(auto& f : m_viz->m_surfaceFormats)
                if(fmt == f.format)
                    return true;
            return false;
        }
        
        bool                Viewer::supports(PresentMode pm) const
        {
            return m_viz->m_presentModes.contains(pm);
        }

        VkSurfaceKHR        Viewer::surface() const 
        { 
            return m_viz->m_surface; 
        }

        VkFormat            Viewer::surface_format() const
        {
            return m_viz->m_surfaceFormat;
        }

        VkColorSpaceKHR  Viewer::surface_color_space() const 
        { 
            return m_viz->m_surfaceColorSpace; 
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
            return m_viz->m_videoDecode[i];
        }
        
        uint32_t  Viewer::video_decode_queue_count() const
        {
            return (uint32_t) m_viz->m_videoDecode.queues.size();
        }
        
        uint32_t  Viewer::video_decode_queue_family() const
        {
            return m_viz->m_videoDecode.family;
        }

        VkQueue   Viewer::video_encode_queue(uint32_t i) const
        {
            return m_viz->m_videoEncode[i];
        }
        
        uint32_t  Viewer::video_encode_queue_count() const
        {
            return (uint32_t) m_viz->m_videoEncode.queues.size();
        }

        uint32_t  Viewer::video_encode_queue_family() const
        {
            return m_viz->m_videoEncode.family;
        }

        int  Viewer::width() const
        {
            if(!m_viz->m_window)
                return 0;
        
            int ret;
            glfwGetWindowSize(m_viz->m_window, &ret, nullptr);
            return ret;
        }
        
        GLFWwindow*         Viewer::window() const 
        { 
            return m_viz->m_window; 
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
                if (vkAllocateCommandBuffers(viz->m_device, &allocInfo, &commandBuffer) != VK_SUCCESS) 
                    throw VqException("Failed to allocate command buffers!");

                VqFenceCreateInfo   fci;
                fci.flags = VK_FENCE_CREATE_SIGNALED_BIT;
                if(vkCreateFence(viz->m_device, &fci, nullptr,  &fence) != VK_SUCCESS)
                    throw VqException("Unable to create fence!");

                VqSemaphoreCreateInfo   info;
                if(vkCreateSemaphore(viz->m_device, &info, nullptr, &imageAvailable) != VK_SUCCESS)
                    throw VqException("Unable to create semaphore!");
                if(vkCreateSemaphore(viz->m_device, &info, nullptr, &renderFinished) != VK_SUCCESS)
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
                    vkFreeCommandBuffers(viz->m_device, viz->m_thread->graphic, 1, &commandBuffer);
                    commandBuffer   = nullptr;
                }
                
                if(imageAvailable){
                    vkDestroySemaphore(viz->m_device, imageAvailable, nullptr);
                    imageAvailable  = nullptr;
                }
                
                if(renderFinished){
                    vkDestroySemaphore(viz->m_device, renderFinished, nullptr);
                    renderFinished  = nullptr;
                }
                
                if(fence){
                    vkDestroyFence(viz->m_device, fence, nullptr);
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

        void    ViQueues::set(VkDevice dev, uint32_t cnt)
        {
            queues.clear();
            queues.resize(cnt, nullptr);
            for(uint32_t i=0;i<cnt;++i)
                vkGetDeviceQueue(dev, family, i, &queues[i]);
        }
        
        ViQueues::~ViQueues()
        {
            queues.clear();
        }

        VkQueue ViQueues::operator[](uint32_t i) const
        {
            if(i<queues.size()) [[likely]]
                return queues[i];
            return nullptr;
        }


        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////

        ViShader::ViShader()
        {
        }
        
        ViShader::~ViShader()
        {
            if(device && shader){
                vkDestroyShaderModule(device, shader, nullptr);
                device  = nullptr;
                shader  = nullptr;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////

        ViSwapchain::ViSwapchain(Visualizer* viz_) : viz(viz_)
        {
            try {
                if(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(viz->m_physical, viz->m_surface, &capabilities) != VK_SUCCESS)
                    throw VqException("Unable to get surface capabilities");
                if (capabilities.currentExtent.width != std::numeric_limits<uint32_t>::max()) {
                    extents = capabilities.currentExtent;
                } else {
                    int w, h;
                    glfwGetFramebufferSize(viz->m_window, &w, &h);
                    extents = {};
                    extents.width       = std::clamp((uint32_t) w, capabilities.minImageExtent.width, capabilities.maxImageExtent.width);
                    extents.height      = std::clamp((uint32_t) h, capabilities.minImageExtent.height, capabilities.maxImageExtent.height);
                }

                #if 0
                int w, h;
                glfwGetFramebufferSize(viz.m_window, &w, &h);
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
                swapInfo.surface          = viz->m_surface;
                swapInfo.minImageCount    = imageCount;
                swapInfo.imageFormat      = viz->m_surfaceFormat;
                swapInfo.imageColorSpace  = viz->m_surfaceColorSpace;
                swapInfo.imageExtent      = extents;
                swapInfo.imageArrayLayers = 1;    // we're not steroscopic (YET)  <-- OCULUS HERE
                swapInfo.imageUsage       = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
                
                uint32_t queueFamilyIndices[] = {viz->m_graphic.family, viz->m_present.family};
                if (viz->m_graphic.family != viz->m_present.family) {
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
                swapInfo.presentMode      = (VkPresentModeKHR) viz->m_presentMode.value();
                swapInfo.clipped          = VK_TRUE;
                
                    // TEMPORARY UNTIL WE GET THE NEW ONE
                if(viz->m_swapchain){
                    swapInfo.oldSwapchain = viz->m_swapchain->swapchain;
                } else {
                    swapInfo.oldSwapchain = nullptr;
                }
                    
                if (vkCreateSwapchainKHR(viz->m_device, &swapInfo, nullptr, &swapchain) != VK_SUCCESS)
                    throw VqException("Failed to create the SWAP chain!");

                if(vkGetSwapchainImagesKHR(viz->m_device, swapchain, &imageCount, nullptr) != VK_SUCCESS)
                    throw VqException("Unable to get image count.");
                images.resize(imageCount, nullptr);
                if(vkGetSwapchainImagesKHR(viz->m_device, swapchain, &imageCount, images.data()) != VK_SUCCESS)
                    throw VqException("Unable to get images!");
                                
                imageViews.resize(imageCount, nullptr);

                VqImageViewCreateInfo       imageViewInfo;
                imageViewInfo.viewType     = VK_IMAGE_VIEW_TYPE_2D;
                imageViewInfo.format       = viz->m_surfaceFormat;
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
                    if(vkCreateImageView(viz->m_device, &imageViewInfo, nullptr, &imageViews[i]) != VK_SUCCESS) 
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
                    if (vkCreateFramebuffer(viz->m_device, &frameBufferInfo, nullptr, &frameBuffers[i]) != VK_SUCCESS) 
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
                        vkDestroyFramebuffer(viz->m_device, frameBuffers[i], nullptr);
                    if((i < imageViews.size()) && imageViews[i])
                        vkDestroyImageView(viz->m_device, imageViews[i], nullptr);
                }
                frameBuffers.clear();
                imageViews.clear();
                images.clear();
                if(swapchain){
                    vkDestroySwapchainKHR(viz->m_device, swapchain, nullptr);
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
                if(vkCreateDescriptorPool(viz->m_device, &descriptorPoolInfo, nullptr, &descriptors) != VK_SUCCESS)
                    throw VqException("Unable to allocate the descriptor pool!");

                VqCommandPoolCreateInfo poolInfo;
                poolInfo.flags              = viz->m_cmdPoolCreateFlags;
                
                if(viz->m_graphic.valid()){
                    poolInfo.queueFamilyIndex   = viz->m_graphic.family;
                    if (vkCreateCommandPool(viz->m_device, &poolInfo, nullptr, &graphic) != VK_SUCCESS) 
                        throw VqException("Failed to create a graphic command pool!");
                }
                if(viz->m_compute.valid()){
                    poolInfo.queueFamilyIndex   = viz->m_compute.family;
                    if (vkCreateCommandPool(viz->m_device, &poolInfo, nullptr, &compute) != VK_SUCCESS) 
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
                    vkDestroyDescriptorPool(viz->m_device, descriptors, nullptr);
                    descriptors = nullptr;
                }
                if(graphic){
                    vkDestroyCommandPool(viz->m_device, graphic, nullptr);
                    graphic = nullptr;
                }
                if(compute){
                    vkDestroyCommandPool(viz->m_device, compute, nullptr);
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
            m_window        = w->m_window;
            
            try {
                _ctor(vci);
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

        namespace {
            std::vector<float>      make_weights(const VqQueueSpec& qs, uint32_t mincnt=0)
            { 
                if(const std::vector<float>*p = std::get_if<std::vector<float>>(&qs)){
                    if((!p->empty()) && (p->size() >= (size_t) mincnt))
                        return *p;
                }
                uint32_t    cnt = mincnt;
                if(const uint32_t* p = std::get_if<uint32_t>(&qs))
                    cnt = std::max(cnt, *p);
                if(const bool* p = std::get_if<bool>(&qs)){
                    if(*p)
                        cnt = std::max<uint32_t>(cnt, 1);
                }
                if(cnt){
                    std::vector<float> ret;
                    ret.resize(cnt, 1.);
                    return ret;
                }
                return std::vector<float>();
            }
        }


        void Visualizer::_ctor(const ViewerCreateInfo& vci)
        {
            Application*   app    = Application::app();
            if(!app)
                throw VqException("Unintialized or no application present!");

            app -> init_vulkan();

            m_instance    = app->instance();
            if(!m_instance)
                throw VqException("Vulkan has not been initialized!");



            //  ================================
            //  SELECT GPU (ie, physical device)

            m_physical                    = vci.device;
            if(!m_physical){
                m_physical  = vqFirstDevice();
                if(!m_physical)
                    throw VqException("Cannot create m_window without any devices!");
            }
            
            vkGetPhysicalDeviceProperties(m_physical, &m_deviceInfo);
            vkGetPhysicalDeviceMemoryProperties(m_physical, &m_memoryInfo);


            //  ================================
            //  GLFW "SURFACE"

            if(glfwCreateWindowSurface(m_instance, m_window, nullptr, &m_surface) != VK_SUCCESS)
                throw VqException("Unable to create window surface!");
                
            for(auto pm : vqGetPhysicalDeviceSurfacePresentModesKHR(m_physical, m_surface))
                m_presentModes.insert((PresentMode::enum_t) pm);
            m_surfaceFormats        = vqGetPhysicalDeviceSurfaceFormatsKHR(m_physical, m_surface);
            
            // right now, cheating on format & color space
            m_surfaceFormat         = VK_FORMAT_B8G8R8A8_SRGB;
            m_surfaceColorSpace     = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;

            //  ================================
            //  LOGICAL DEVICE CREATION
            //
            //  Buckle up, this is a long one

                // list extensions, augmenting with swap chain
                
            std::vector<const char*>    devExtensions = vci.extensions;
            devExtensions.push_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);

                //  Query the GPU for valid queue families
            auto queueInfos         = vqFindQueueFamilies(m_physical, m_surface);
            
                //  And we need to create them... so request
            std::vector<VkDeviceQueueCreateInfo> qci;
            
                //  graphic is required....
            std::vector<float>  graphicWeights  = make_weights(vci.graphic, 1);
            if(!queueInfos.graphics.has_value()){
                throw VqException("No graphic queue capability!");
            } else {
                m_graphic.family        = queueInfos.graphics.value();
                VqDeviceQueueCreateInfo info;
                info.queueFamilyIndex   = m_graphic.family;
                info.queueCount         = (uint32_t) graphicWeights.size();
                info.pQueuePriorities   = graphicWeights.data();
                qci.push_back(info);
            }
            
                //  present is required....
            std::vector<float>  presentWeights  = make_weights(vci.present, 1);
            if(!queueInfos.present.has_value()){
                throw VqException("No graphic queue capability!");
            } else {
                m_present.family        = queueInfos.present.value();
                VqDeviceQueueCreateInfo info;
                info.queueFamilyIndex   = m_present.family;
                info.queueCount         = (uint32_t) presentWeights.size();
                info.pQueuePriorities   = presentWeights.data();
                qci.push_back(info);
            }
            
                //  Determine if compute is requested, create the request
            std::vector<float>  computeWeights  = make_weights(vci.compute, 0);
            if(!computeWeights.empty()){
                if(!queueInfos.compute.has_value()){
                    throw VqException("No compute queue capability!");
                } else {
                    m_compute.family        = queueInfos.compute.value();
                    VqDeviceQueueCreateInfo info;
                    info.queueFamilyIndex   = m_compute.family;
                    info.queueCount         = (uint32_t) computeWeights.size();
                    info.pQueuePriorities   = computeWeights.data();
                    qci.push_back(info);
                }
            }

                //  Determine if video decoding is requested, create the request
            std::vector<float>  videoDecWeights = make_weights(vci.video_decode, 0);
            if(!videoDecWeights.empty()){
                if(!queueInfos.videoDecode.has_value()){
                    throw VqException("No video decode queue capability!");
                } else {
                    m_videoDecode.family    = queueInfos.videoDecode.value();
                    VqDeviceQueueCreateInfo info;
                    info.queueFamilyIndex   = m_videoDecode.family;
                    info.queueCount         = (uint32_t) videoDecWeights.size();
                    info.pQueuePriorities   = videoDecWeights.data();
                    qci.push_back(info);
                }
            }
            
                //  Determine if video encoding is requested, create the request
            std::vector<float>  videoEncWeights = make_weights(vci.video_encode, 0);
            if(!videoEncWeights.empty()){
                if(!queueInfos.videoEncode.has_value()){
                    throw VqException("No video encode queue capability!");
                } else {
                    m_videoEncode.family    = queueInfos.videoEncode.value();
                    VqDeviceQueueCreateInfo info;
                    info.queueFamilyIndex   = m_videoEncode.family;
                    info.queueCount         = (uint32_t) videoEncWeights.size();
                    info.pQueuePriorities   = videoEncWeights.data();
                    qci.push_back(info);
                }
            }
            
            std::sort(qci.begin(), qci.end(), [](const VkDeviceQueueCreateInfo& a, const VkDeviceQueueCreateInfo& b) -> bool {
                return a.queueFamilyIndex < b.queueFamilyIndex;
            });
            
            for(size_t i=0;i<qci.size()-1;++i){
                VkDeviceQueueCreateInfo&    prev  = qci[i];
                VkDeviceQueueCreateInfo&    next  = qci[i+1];
                if(prev.queueFamilyIndex != next.queueFamilyIndex)
                    continue;
                
                //  carry the request forward
                if(next.queueCount < prev.queueCount){
                    //  steal the pointer
                    next.queueCount         = prev.queueCount;
                    next.pQueuePriorities   = prev.pQueuePriorities;
                }
                prev.queueFamilyIndex   = UINT32_MAX;
            }
            
            auto qitr = std::remove_if(qci.begin(), qci.end(), [](const VkDeviceQueueCreateInfo& a) -> bool {
                return a.queueFamilyIndex == UINT32_MAX;
            });
            if(qitr != qci.end())
                qci.erase(qitr, qci.end());
                    
            //  And with that, we have the queues all lined up, ready to be created.

            VkPhysicalDeviceFeatures    gpu_features{};
            if(vci.fill_non_solid)
                gpu_features.fillModeNonSolid    = VK_TRUE;

            VqDeviceCreateInfo          deviceCreateInfo;
            deviceCreateInfo.pQueueCreateInfos        = qci.data();
            deviceCreateInfo.queueCreateInfoCount     = (uint32_t) qci.size();
            deviceCreateInfo.pEnabledFeatures         = &gpu_features;
            
            const auto& layers = app->layers();
            
            deviceCreateInfo.enabledLayerCount          = (uint32_t) layers.size();
            if(deviceCreateInfo.enabledLayerCount)
                deviceCreateInfo.ppEnabledLayerNames    = layers.data();
        
            deviceCreateInfo.enabledExtensionCount      = (uint32_t) devExtensions.size();
            deviceCreateInfo.ppEnabledExtensionNames    = devExtensions.data();
            
            VqPhysicalDeviceVulkan12Features            v12features;
            v12features.bufferDeviceAddress = true;
            deviceCreateInfo.pNext          = &v12features;
            
            if(vkCreateDevice(m_physical, &deviceCreateInfo, nullptr, &m_device) != VK_SUCCESS)
                throw VqException("Unable to create logical device!");
            
            //  ================================
            //  GETTING THE QUEUES

            m_graphic.set(m_device, graphicWeights.size());
            m_present.set(m_device, presentWeights.size());
            if(m_compute.family != UINT32_MAX)
                m_compute.set(m_device, computeWeights.size());
            if(m_videoEncode.family != UINT32_MAX)
                m_videoEncode.set(m_device, videoEncWeights.size());
            if(m_videoDecode.family != UINT32_MAX)
                m_videoDecode.set(m_device, videoDecWeights.size());

            //  ================================
            //  ALLOCATOR

            VmaAllocatorCreateInfo      allocatorCreateInfo{};
            allocatorCreateInfo.instance                        = m_instance;
            allocatorCreateInfo.physicalDevice                  = m_physical;
            allocatorCreateInfo.device                          = m_device;
            allocatorCreateInfo.vulkanApiVersion                = app->app_info().vulkan_api;
            allocatorCreateInfo.preferredLargeHeapBlockSize     = (VkDeviceSize) vci.chunk_size;
            vmaCreateAllocator(&allocatorCreateInfo, &m_allocator);

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
            
            if(m_allocator){
                vmaDestroyAllocator(m_allocator);
                m_allocator = nullptr;
            }
            
            {
                tbb::spin_rw_mutex::scoped_lock _lock(m_shaders.mutex, true);
                m_shaders.map.clear();
            }
            
            if(m_device){
                vkDestroyDevice(m_device, nullptr);
                m_device                = nullptr;
            }
            m_graphic                   = {};
            m_present                   = {};
            m_compute                   = {};
            m_videoEncode               = {};
            m_videoDecode               = {};
            
            if(m_surface){
                vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
                m_surface               = nullptr;
            }
            m_physical                  = nullptr;
            m_window                    = nullptr;
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
        //  SHADER MANAGEMENT

            ViShaderCPtr                Visualizer::shader(const ShaderSpec&ss)
            {
                //  ================================
                //  Resolve the request
            
                ShaderCPtr       sh;
                if(const ShaderCPtr* ptr = std::get_if<ShaderCPtr>(&ss)){
                    sh  = *ptr;
                } else if(const std::string* ptr = std::get_if<std::string>(&ss)){
                    sh  = Shader::get(*ptr); 
                } 
                if(!sh)
                    return nullptr;
                
                if(sh->shader_type() == ShaderType::UNKNOWN)
                    return nullptr;
                
                //  ================================
                //  Check for existing

                ViShaderCPtr ret  = nullptr;
                {
                    tbb::spin_rw_mutex::scoped_lock    _lock(m_shaders.mutex, false);
                    auto j = m_shaders.map.find(sh->id());
                    if(j != m_shaders.map.end())
                        ret = j->second;
                }
                
                if(ret){
                    ret -> tick = m_tick;
                    return ret;
                }
                
                //  ================================
                //   Create a shader module
                
                VkShaderStageFlagBits    mask    = {};
                
                switch(sh->shader_type()){
                case ShaderType::VERT:
                    mask = VK_SHADER_STAGE_VERTEX_BIT;
                    break;
                case ShaderType::TESC:
                    mask = VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
                    break;
                case ShaderType::TESE:
                    mask = VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
                    break;
                case ShaderType::FRAG:
                    mask = VK_SHADER_STAGE_FRAGMENT_BIT;
                    break;
                case ShaderType::GEOM:
                    mask = VK_SHADER_STAGE_GEOMETRY_BIT;
                    break;
                case ShaderType::COMP:
                    mask = VK_SHADER_STAGE_COMPUTE_BIT;
                    break;
                default:
                    return nullptr;
                }
                    
                VkShaderModule  sm  = nullptr;
                
                const ByteArray&    code    = sh->payload();
                VqShaderModuleCreateInfo createInfo;
                createInfo.codeSize = code.size();
                createInfo.pCode    = reinterpret_cast<const uint32_t*>(code.data());
                if (vkCreateShaderModule(m_device, &createInfo, nullptr, &sm) != VK_SUCCESS) {
                    yError() << "Unable to create shader module.";
                    return nullptr ;
                }
                
                //  ================================
                //   Create our tracker

                ViShader*  p = new ViShader;
                p->device   = m_device;
                p->shader   = sm;
                p->mask     = mask;
                p->tick     = m_tick;
                
                ViShaderCPtr    ours(p);
                
                //  ================================
                //   Register it (checking for collisions)
                
                {
                    tbb::spin_rw_mutex::scoped_lock _lock(m_shaders.mutex, true);
                    auto j    = m_shaders.map.emplace(sh->id(), ours);
                    if(j.second) [[likely]]
                        return ours;
                    ret = j.first->second;   // Somebody beat us to it... use theirs
                    if(!ret){ [[unlikely]]  // It's NULL (shouldn't happen)
                        m_shaders.map[sh->id()] = ours;
                        return ours;
                    }
                }

                //  ================================
                //   Collision!

                return ret;
            }

            ViShaderCPtr  Visualizer::shader(uint64_t i) const
            {
                ViShaderCPtr     ret = nullptr;
                {
                    tbb::spin_rw_mutex::scoped_lock _lock(m_shaders.mutex, false);
                    auto j  = m_shaders.map.find(i);
                    if(j == m_shaders.map.end())
                        return nullptr;
                    ret = j->second;
                }
                
                if(ret)
                    ret -> tick = m_tick;
                return ret;
            }

            size_t   Visualizer::shader_count() const
            {
                tbb::spin_rw_mutex::scoped_lock _lock(m_shaders.mutex, false);
                return m_shaders.map.size();
            }

            void    Visualizer::shader_purge(uint64_t cutoff)
            {
                std::vector<ViShaderCPtr>   trash;
                trash.reserve(shader_count());
                {
                    tbb::spin_rw_mutex::scoped_lock _lock(m_shaders.mutex, true);
                    for(auto i=m_shaders.map.begin(), last=m_shaders.map.end(); i!=last; ){
                        if((!i->second) || (i->second->tick < cutoff)){
                            trash.push_back(std::move(i->second));
                            i = m_shaders.map.erase(i);
                        } else
                            ++i;
                    }
                }
            }

        //  ----------------------------------------------------------------------------
        //  ----------------------------------------------------------------------------

        VkSurfaceCapabilitiesKHR    Visualizer::surface_capabilities() const
        {
            VkSurfaceCapabilitiesKHR    ret;
            if(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(m_physical, m_surface, &ret) != VK_SUCCESS)
                throw VqException("Unable to get surface capabilities");
            return ret;
        }


        VkColorSpaceKHR Visualizer::surface_color_space(VkFormat fmt) const
        {
            for(auto& f : m_surfaceFormats)
                if(fmt == f.format)
                    return f.colorSpace;
            return VK_COLOR_SPACE_MAX_ENUM_KHR;
        }
        
        YQ_INVOKE(
            writer<Viewer>();
        )
        
    }
}

