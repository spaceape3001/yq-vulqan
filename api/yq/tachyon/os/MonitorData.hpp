////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/color/RGB.hpp>
#include <yq/shape/Rectangle2.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/os/VideoMode.hpp>
#include <yq/tachyon/typedef/monitor.hpp>

namespace yq::tachyon {

    #if 0
    struct MonitorState {
        //  Right now, keyed to GLFW, but can be altered...
        Vector2I                position;
        Rectangle2I             working;
        Vector2F                scale;
        std::string             name;
        std::vector<RGB3U16>    gamma; //!< Will be 256 sized on windows, if specified
        std::vector<VideoMode>  video_modes;
        size_t                  video_mode  = ~0ULL;
    };
    #endif
    
    struct MonitorSnap : public TachyonSnap /* , public MonitorState */ {
        Size2MM     dimensions;
        Size2D      size;
        Vector2F    scale;
    };
    
    struct MonitorData : public TachyonData {
    };
}
