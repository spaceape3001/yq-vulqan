////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/keywords.hpp>

namespace yq::tachyon::im {
    struct button_options_t {
        ImVec2  size    = { 0., 0. };
    };

    bool    button(const char* label, const button_options_t& opts={});
    bool    button(primary_k, const char* label, const button_options_t& opts={});
    bool    button(secondary_k, const char* label, const button_options_t& opts={});
}
