////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size2.hpp>
#include <yq/vector/Vector2.hpp>

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/app/GEnvCreateInfo.hpp>
#include <yq/tachyon/pipeline/PresentMode.hpp>
#include <yq/tachyon/os/WindowMode.hpp>
#include <yq/tachyon/typedef/monitor.hpp>

//#include <vulkan/vulkan_core.h>
#include <vector>

namespace yq::tachyon {

    struct ViewerCreateInfo : public GEnvCreateInfo {
    
        std::string                 title    = "(untitled)";
        Size2I                      size     = { 1920, 1080 };
        std::optional<Vector2I>     position;
            //!  Set to get full screen, windowed otherwise
        MonitorID                   monitor;
        PresentMode                 pmode   = PresentMode::Fifo;
        WindowMode                  wmode   = WindowMode::Normal;
        

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
        
        
            //!  Number of frames in flight (2..3)
        uint32_t                    frames_in_flight    = 2;
        
        ViewerCreateInfo(){}
    };
}
