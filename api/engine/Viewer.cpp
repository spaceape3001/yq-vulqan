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
#include <meta/ObjectInfoWriter.hpp>

#include <tachyon/Camera.hpp>
#include <tachyon/gfx/Shader.hpp>

#include <engine/render/IndexBufferObjectInfo.hpp>
#include <engine/render/Pipeline.hpp>
#include <tachyon/gfx/PipelineConfig.hpp>
#include <engine/render/PushBufferObjectInfo.hpp>
#include <engine/render/Rendered.hpp>
#include <engine/render/Render3D.hpp>
#include <tachyon/gfx/PushData.hpp>
#include <engine/render/UniformBufferObjectInfo.hpp>
#include <engine/render/VertexBufferObjectInfo.hpp>

#include <engine/vulqan/VqBuffer.hpp>
#include <engine/vulqan/VqPipeline.hpp>


#include <tachyon/gpu/VqException.hpp>
#include <tachyon/gpu/VqLogging.hpp>
#include <tachyon/gpu/VqStructs.hpp>
#include <tachyon/gpu/VqUtils.hpp>
#include <tachyon/ui/UiContext.hpp>

#include <math/shape/Size2.hpp>
#include <math/vector/Vector2.hpp>

#include <algorithm>
#include <cassert>

#include <GLFW/glfw3.h>

#include <tachyon/ui/MyImGui.hpp>
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
                    vii.MinImageCount   = m_viz->swapchain_min_image_count();
                    vii.ImageCount      = m_viz->swapchain_image_count();
                    vii.DescriptorPool  = m_viz->descriptor_pool();
                    
                    ImGui::SetCurrentContext(m_imgui);
                    ImGui_ImplGlfw_InitForVulkan(window(), false);
                    ImGui_ImplVulkan_Init(&vii, m_viz->render_pass());
                    
                    //  Uploading fonts....
                    
                    VkCommandBuffer cbuffer = m_viz->command_buffer();

                    vkResetCommandPool(m_viz->device(), m_viz->command_pool(), 0);
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
            UiContext   u(*m_viz);
            if(m_imgui){
                u.imgui_enabled = true;
                ImGui::SetCurrentContext(m_imgui);
                ImGui_ImplVulkan_NewFrame();
                ImGui_ImplGlfw_NewFrame();
                ImGui::NewFrame();
                draw_imgui(u);
                ImGui::Render();
            }
            m_viz->draw(u, [&](UiContext&u){
                draw_vulqan(u.cmd);
                if(m_imgui)
                    ImGui_ImplVulkan_RenderDrawData(ImGui::GetDrawData(), u.cmd, nullptr);
            });
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
    
            Camera::Params      cparams;
            cparams.screen      = (Size2D) size();
            glm::dmat4          cam_matrix = pr.camera->world2screen(cparams);
            
            VkPipeline          prev_pipeline   = nullptr;
            tachyon::StdPushData     stdPush;
            
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
                case tachyon::PushConfigType::Full:
                    if(r3){
                        stdPush.matrix  = cam_matrix * r3->model2world();
                        vkCmdPushConstants(buf, vklay, shader_mask, 0, sizeof(stdPush), &stdPush );
                    }
                    break;
                case tachyon::PushConfigType::View:
                    stdPush.matrix  = cam_matrix;
                    vkCmdPushConstants(buf, vklay, shader_mask, 0, sizeof(stdPush), &stdPush );
                    break;
                case tachyon::PushConfigType::Custom:
                    {
                        const PushBufferObjectInfo* pbo = pipe->push_buffer();
                        if(pbo){
                            BufferData      bd  = pbo->get(r);
                            if(bd.data && bd.size)
                                vkCmdPushConstants(buf, vklay, shader_mask, 0, bd.size, bd.data);
                        }
                    }
                    break;
                case tachyon::PushConfigType::None:
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
            return m_viz->command_buffer();
        }

        VkCommandPool  Viewer::command_pool() const 
        { 
            return m_viz->command_pool();
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
            return m_viz->descriptor_pool(); 
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
            return m_viz->render_pass();
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
            return m_viz->swapchain_def_scissor();
        }
        
        VkViewport  Viewer::swap_def_viewport() const
        {
            return m_viz->swapchain_def_viewport();
        }

        uint32_t    Viewer::swap_image_count() const
        {
            return m_viz->swapchain_image_count();
        }

        uint32_t    Viewer::swap_height() const
        {
            return m_viz->swapchain_height();
        }

        uint32_t    Viewer::swap_min_image_count() const
        {
            return m_viz->swapchain_min_image_count();
        }

        uint32_t    Viewer::swap_width() const
        {
            return m_viz->swapchain_width();
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
        

        Visualizer::Visualizer(const ViewerCreateInfo& vci, Viewer *w)
        {
            m_viewer        = w;
            std::error_code ec  = init_visualizer(vci, w->window());
            if(ec){
               _dtor();
               throw ec; 
            }
        }

        Visualizer::~Visualizer()
        {
            _dtor();
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
            
            
            kill_visualizer();
            
            m_viewer                    = nullptr;
        }

        using tachyon::ViFrame;

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

