////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/MyImGui.hpp>
#include <yq/typedef/quaternion3.hpp>
#include <yq/typedef/range.hpp>
#include <yq/typedef/rectangle2.hpp>
#include <yq/typedef/rgb.hpp>
#include <yq/typedef/rgba.hpp>
#include <yq/typedef/size2.hpp>
#include <yq/typedef/size3.hpp>
#include <yq/typedef/size4.hpp>
#include <yq/typedef/tensor44.hpp>
#include <yq/typedef/uv.hpp>
#include <yq/typedef/uvw.hpp>
#include <yq/typedef/vector1.hpp>
#include <yq/typedef/vector2.hpp>
#include <yq/typedef/vector3.hpp>
#include <yq/typedef/vector4.hpp>

namespace yq::tachyon::im {
    struct input_float_t {
        //const char*             drag            = nullptr;
        //ImGuiDragDropFlags      drag_flags      = 0;
        //string_view_vector_t    drop;
        //ImGuiDragDropFlags      drop_flags      = 0;
        ImGuiInputTextFlags     flags           = 0;
        const char*             format          = "%.3f";
        bool                    labelless       = true;
        float                   max             = 0.0;
        float                   min             = 0.0;
        float                   step            = 0.0;
        float                   step_fast       = 0.0;
    };
    
    struct input_float_quaternion_t {
        //const char*             drag            = nullptr;
        //ImGuiDragDropFlags      drag_flags      = 0;
        //string_view_vector_t    drop;
        //ImGuiDragDropFlags      drop_flags      = 0;
        ImGuiInputTextFlags     flags           = 0;
        const char*             format          = "%.4f";
        bool                    labelless       = true;
        float                   max             = 0.0;
        float                   min             = 0.0;
        float                   step            = 0.0;
        float                   step_fast       = 0.0;
    };
    
    bool    input(const char* label, float&, const input_float_t& opts={});
    bool    input(const char* label, unsigned, float*, const input_float_t& opts={});
    
    bool    input(const char* label, Quaternion3F&, const input_float_quaternion_t& opts={});
    bool    input(const char* label, RangeF&, const input_float_t& opts={});
    bool    input(const char* label, RGB3F&, const input_float_t& opts={});
    bool    input(const char* label, RGBA4F&, const input_float_t& opts={});
    bool    input(const char* label, Size2F&, const input_float_t& opts={});
    bool    input(const char* label, Size3F&, const input_float_t& opts={});
    bool    input(const char* label, Size4F&, const input_float_t& opts={});
    bool    input(const char* label, UV2F&, const input_float_t& opts={});
    bool    input(const char* label, UVW3F&, const input_float_t& opts={});
    bool    input(const char* label, Vector1F&, const input_float_t& opts={});
    bool    input(const char* label, Vector2F&, const input_float_t& opts={});
    bool    input(const char* label, Vector3F&, const input_float_t& opts={});
    bool    input(const char* label, Vector4F&, const input_float_t& opts={});
}
