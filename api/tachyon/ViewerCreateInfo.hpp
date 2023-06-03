////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <math/color/RGBA.hpp>
#include <math/shape/Size2.hpp>
#include <math/vector/Vector2.hpp>

#include <tachyon/preamble.hpp>
#include <tachyon/ViewerCreateInfo.hpp>
#include <tachyon/enum/PresentMode.hpp>
#include <tachyon/host/Monitor.hpp>
#include <vulkan/vulkan_core.h>
#include <variant>
#include <vector>

namespace yq::tachyon {
    using ViQueueSpec = std::variant<std::monostate, bool, uint32_t, std::vector<float>>;

    struct ViewerCreateInfo {
        VkPhysicalDevice            device   = nullptr;
    
        std::string                 title    = "(untitled)";
        Size2I                      size     = { 1920, 1080 };
        std::optional<Vector2I>     position;
            //!  Set to get full screen, windowed otherwise
        Monitor                     monitor;
        PresentMode                 pmode   = PresentMode::Fifo;
        
        
            //!  This is the background color
        RGBA4F                      clear   = { 0., 0., 0., 1. };
        
            //!  Set to make always-on-top
        bool                        floating    = false;
        
            //!  Set to make decorated
        bool                        decorated   = true;
        
            //!  Set to make user-resizable
        bool                        resizable   = false;
        
            //!  Set to enable imgui
        bool                        imgui       = false;
        
            //!  Set to enable fill of non-solid features
        bool                        fill_non_solid  = true;
            
            //!  Set to alter graphic queue capability
        ViQueueSpec                 graphic;

            //!  Set to alter present queue capability
        ViQueueSpec                 present;


            //!  Set to enable compute queue capability
        ViQueueSpec                 compute;
        
            //!  Set to enable video-decode queue capability
        ViQueueSpec                 video_decode;
        
            //!  Set to enable video-encode queue capability
        ViQueueSpec                 video_encode;

            //!     Set to get descriptors allocated
        uint32_t                    descriptors = 0;
        
            //!  Amount to allocate in "chunks" on the GPU (Zero implies default...currently 256MiB)
        size_t                      chunk_size  = 0;
        
            //!  Number of frames in flight
        size_t                      frames_in_flight    = 2;
        
            //! Device extensions
        std::vector<const char*>    extensions;
        
        ViewerCreateInfo(){}
    };
}
