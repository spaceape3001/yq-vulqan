////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/TachyonLog.hpp>
#include <tachyon/Application.hpp>
#include <tachyon/Viewer.hpp>
#include <tachyon/ViewerCreateInfo.hpp>
#include <tachyon/gpu/VqStructs.hpp>
#include <tachyon/ui/Widget2.hpp>
#include <tachyon/gpu/ViContext.hpp>
#include <tachyon/ui/MyImGui.hpp>

#include <basic/AutoReset.hpp>
#include <basic/ErrorDB.hpp>
#include <basic/errors.hpp>

#include <backends/imgui_impl_vulkan.h>
#include <backends/imgui_impl_glfw.h>

namespace yq {
    namespace tachyon {

        Viewer::Viewer()
        {
        }
        
        Viewer::~Viewer()
        {
            kill();
        }

        Viewer::Viewer(const ViewerCreateInfo&vci, Widget2*w) : Viewer()
        {
        
            std::error_code ec = initialize(vci, w);
            if(ec){
                tachyonCritical << "Unable to initialize the viewer ... " << ec.message();
                throw ec;
            }
        }

        std::error_code     Viewer::initialize(const ViewerCreateInfo&vci, Widget2* w)
        {
            if(m_widget)
                return std::error_code();

            if(!w)
                return errors::null_pointer();
        
            Application::initialize();

            std::error_code ec = init_window(vci);
            if(ec)
                return ec;
            ec  = init_visualizer(vci, window());
            if(ec)
                return ec;
             
            if(vci.imgui){
                m_imgui = ImGui::CreateContext();

                ImGui_ImplVulkan_InitInfo vii{};
                
                vii.Instance        = instance();
                vii.PhysicalDevice  = physical();
                vii.Device          = device();
                vii.Queue           = graphic_queue(0);
                vii.QueueFamily     = graphic_queue_family();
                vii.MinImageCount   = swapchain_min_image_count();
                vii.ImageCount      = swapchain_image_count();
                vii.DescriptorPool  = descriptor_pool();
                
                ImGui::SetCurrentContext(m_imgui);
                ImGui_ImplGlfw_InitForVulkan(window(), false);
                ImGui_ImplVulkan_Init(&vii, render_pass());
                
                //  Uploading fonts....
                
                VkCommandBuffer cbuffer = command_buffer();

                vkResetCommandPool(device(), command_pool(), 0);
                VqCommandBufferBeginInfo begin_info;
                begin_info.flags |= VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
                vkBeginCommandBuffer(cbuffer, &begin_info);

                ImGui_ImplVulkan_CreateFontsTexture(cbuffer);

                VqSubmitInfo end_info;
                end_info.commandBufferCount = 1;
                end_info.pCommandBuffers = &cbuffer;
                vkEndCommandBuffer(cbuffer);
                vkQueueSubmit(graphic_queue(0), 1, &end_info, VK_NULL_HANDLE);
                vkDeviceWaitIdle(device());
                ImGui_ImplVulkan_DestroyFontUploadObjects();
            }

            install_hooks();
            m_widget    = w;
            return std::error_code();
        }

        void                Viewer::kill()
        {
            if(m_widget)
                delete m_widget;
            m_widget    = nullptr;
            if(m_imgui){
                ImGui::SetCurrentContext(m_imgui);
                ImGui_ImplVulkan_Shutdown();
                ImGui_ImplGlfw_Shutdown();
                ImGui::DestroyContext(m_imgui);
                ImGui::SetCurrentContext(nullptr);
                m_imgui     = nullptr;
            }
            kill_visualizer();
            Window::kill_window();
        }

        std::error_code     Viewer::draw()
        {
            ViContext   u;
            return draw(u);
        }

        std::error_code     Viewer::draw(ViContext& u)
        {
            if(m_paused || m_zeroSize)
                return std::error_code();
                
            auto start = std::chrono::high_resolution_clock::now();
            u.m_frameNumber = tick();
            if(m_widget && m_imgui){
                auto r = auto_reset(u.m_imgui, true);
                ImGui::SetCurrentContext(m_imgui);
                ImGui_ImplVulkan_NewFrame();
                ImGui_ImplGlfw_NewFrame();
                ImGui::NewFrame();
                m_widget->imgui_(u);
                ImGui::Render();
            }
            
            std::error_code ec = Visualizer::draw(u);
            auto end   = std::chrono::high_resolution_clock::now();
            m_drawTime          = (end-start).count();
            if(ec != std::error_code())
                tachyonCritical << "Viewer::draw() failed ... " << ec.message();
            return ec;
        }

        void    Viewer::record(ViContext&u)
        {
            if(m_widget)
                m_widget -> vulkan_(u);
            if(m_imgui)
                ImGui_ImplVulkan_RenderDrawData(ImGui::GetDrawData(), u.command(), nullptr);
        }

        void    Viewer::window_framebuffer_resized(const Size2I&s)
        {
            m_zeroSize  = zero_framebuffer();
            trigger_rebuild();
        }

        void    Viewer::set_render_paused(bool v)
        {
            m_paused    = v;
        }
        
        void    Viewer::cmd_pause()
        {
            set_render_paused(true);
        }
        
        void    Viewer::cmd_unpause()
        {
            set_render_paused(false);
        }
    }
}
