////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGBA.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/vector/Vector2.hpp>

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/pipeline/DataFormat.hpp>
#include <yq/tachyon/pipeline/PresentMode.hpp>
#include <yq/tachyon/os/WindowMode.hpp>
#include <yq/tachyon/typedef/monitor.hpp>
#include <yq/tachyon/typedef/queue_spec.hpp>

//#include <vulkan/vulkan_core.h>
#include <variant>
#include <vector>

struct VkPhysicalDevice_T;

namespace yq::tachyon {

    struct ViewerCreateInfo {
    
        VkPhysicalDevice_T*         device   = nullptr;
    
        std::string                 title    = "(untitled)";
        Size2I                      size     = { 1920, 1080 };
        std::optional<Vector2I>     position;
            //!  Set to get full screen, windowed otherwise
        MonitorID                   monitor;
        PresentMode                 pmode   = PresentMode::Fifo;
        WindowMode                  wmode   = WindowMode::Normal;
        
        
            //!  This is the background color
        RGBA4F                      clear   = { 0., 0., 0., 1. };
        
        using depth_spec_t  = std::variant<std::monostate, enable_k, DataFormat>;
        depth_spec_t                depth_buffer;


            //!  Set to make always-on-top
        bool                        floating        = false;
        
            //!  Set to make decorated (several window modes will override)
        bool                        decorated       = true;
        
            //!  Set to make user-resizable (only usable in "normal" mode)
        bool                        resizable       = false;
        
            //!  Master switch to initialize/enable imgui (at all)
        bool                        imgui           = false;
        
            //!  Set to start imgui as enabled (ignored if imgui is false)
        bool                        imgui_enabled   = true;
        
            //!  Set to start imgui as getting keyboard events (ignored if imgui is false)
        bool                        imgui_keyboard  = true;

            //!  Set to start imgui as getting mouse events (ignored if imgui is false)
        bool                        imgui_mouse     = true;

            //!  Set to start "hidden"
        bool                        hidden      = false;
        
            //!  Set to enable fill of non-solid features
        bool                        fill_non_solid  = true;
        
            //!  Set if we want multiview capability (think STEREO/VR)
        bool                        multiview   = false;
            
            //!     Set to get descriptors allocated
        uint32_t                    descriptors = 0;
        
            //!  Number of frames in flight
        size_t                      frames_in_flight    = 2;
        
        ViewerCreateInfo(){}
    };
}
