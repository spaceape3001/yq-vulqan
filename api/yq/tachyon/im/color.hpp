////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/MyImGui.hpp>
#include <yq/typedef/rgb.hpp>
#include <yq/typedef/rgba.hpp>

namespace yq::tachyon::im {

    struct color_edit_t {
        ImGuiColorEditFlags flags   = 0;
        bool                labelless   = true;
    };

    bool    color(const char* label, yq::RGB3F&, const color_edit_t& opts={});
    //bool    color(const char* label, yq::RGB3U8&, const color_edit_t& opts={});
    bool    color(const char* label, yq::RGBA4F&, const color_edit_t& opts={});
    //bool    color(const char* label, yq::RGBA4U8&, const color_edit_t& opts={});

}
