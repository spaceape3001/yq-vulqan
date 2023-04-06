////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Application.hpp>
#include <tachyon/Viewer.hpp>
#include <tachyon/ViewerCreateInfo.hpp>
#include <tachyon/gpu/VqStructs.hpp>
#include <tachyon/ui/Widget2.hpp>
#include <tachyon/ui/UiContext.hpp>
#include <tachyon/ui/MyImGui.hpp>

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
            if(ec)
                throw ec;
        }

        std::error_code     Viewer::initialize(const ViewerCreateInfo&vci, Widget2* w)
        {
            if(m_widget)
                return std::error_code();
        
            if(!w)
                return errors::null_pointer();
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

            //  Event callbacks

            m_widget    = w;
            return std::error_code();
        }

        void                Viewer::kill()
        {
            if(m_widget)
                delete m_widget;
            m_widget    = nullptr;
            kill_visualizer();
            Window::kill_window();
        }

        std::error_code     Viewer::draw()
        {
            UiContext   u;
            return draw(u);
        }

        std::error_code     Viewer::draw(UiContext& u)
        {
            auto start = std::chrono::high_resolution_clock::now();
            u.frame         = ++m_frameNumber;
            if(m_widget && m_imgui){
                u.imgui_enabled = true;
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
            return ec;
        }

        void    Viewer::record(UiContext&u)
        {
            if(m_widget)
                m_widget -> vulkan_(u);
            if(m_imgui)
                ImGui_ImplVulkan_RenderDrawData(ImGui::GetDrawData(), u.cmd, nullptr);
        }

    }
}
