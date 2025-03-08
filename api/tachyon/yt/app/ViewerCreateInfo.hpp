////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGBA.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/vector/Vector2.hpp>

#include <yt/api/ID.hpp>
#include <yt/gfx/PresentMode.hpp>
#include <yt/os/WindowMode.hpp>
#include <yt/typedef/monitor.hpp>
#include <yv/typedef/queue_spec.hpp>

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
        
            //!  Set to make always-on-top
        bool                        floating    = false;
        
            //!  Set to make decorated (several window modes will override)
        bool                        decorated   = true;
        
            //!  Set to make user-resizable (only usable in "normal" mode)
        bool                        resizable   = false;
        
            //!  Set to enable imgui
        bool                        imgui       = false;
        
            //!  Set to start "hidden"
        bool                        hidden      = false;
        
        // Some of these following will likely be moved to floating....
        
        
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
