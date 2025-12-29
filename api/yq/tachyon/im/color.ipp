////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "color.hpp"
#include <yq/color/RGB.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon::im {
    bool    color(const char* label, yq::RGB3F&v, const color_edit_t& opts)
    {
        if(opts.labelless)
            ImGui::SetNextItemWidth(-1);
        return ImGui::ColorEdit3(label, &v.red, opts.flags);
    }
    
    //bool    color(const char* label, yq::RGB3U8&, const color_edit_t& opts={});
    bool    color(const char* label, yq::RGBA4F&v, const color_edit_t& opts)
    {
        if(opts.labelless)
            ImGui::SetNextItemWidth(-1);
        return ImGui::ColorEdit4(label, &v.red, opts.flags);
    }
    
    //bool    color(const char* label, yq::RGBA4U8&, const color_edit_t& opts={});
}
