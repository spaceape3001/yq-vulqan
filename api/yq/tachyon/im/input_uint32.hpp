////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/MyImGui.hpp>
#include <yq/typedef/vector1.hpp>
#include <yq/typedef/vector2.hpp>
#include <yq/typedef/vector3.hpp>
#include <yq/typedef/vector4.hpp>

namespace yq::tachyon::im {
    struct input_uint32_t {
        ImGuiInputTextFlags         flags       = 0;
        const char*                 format      = "%d";
        bool                        labelless   = true;
        unsigned                    step        = 0;
        unsigned                    step_fast   = 0;
    };

    bool    input(const char* label, uint32_t&, const input_uint32_t& opts={});
    bool    input(const char* label, unsigned, uint32_t*, const input_uint32_t& opts={});

    bool    input(const char* label, Vector1U&, const input_uint32_t& opts={});
    bool    input(const char* label, Vector2U&, const input_uint32_t& opts={});
    bool    input(const char* label, Vector3U&, const input_uint32_t& opts={});
    bool    input(const char* label, Vector4U&, const input_uint32_t& opts={});
}
