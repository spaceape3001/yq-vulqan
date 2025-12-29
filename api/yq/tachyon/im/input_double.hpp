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
    struct input_double_t {
        //const char*             drag            = nullptr;
        //ImGuiDragDropFlags      drag_flags      = 0;
        //string_view_vector_t    drop;
        //ImGuiDragDropFlags      drop_flags      = 0;
        ImGuiInputTextFlags     flags           = 0;
        const char*             format          = "%.6lf";
        bool                    labelless       = true;
        double                  max             = 0.0;
        double                  min             = 0.0;
        double                  step            = 0.0;
        double                  step_fast       = 0.0;
    };
    
    struct input_double_quaternion_t {
        //const char*             drag            = nullptr;
        //ImGuiDragDropFlags      drag_flags      = 0;
        //string_view_vector_t    drop;
        //ImGuiDragDropFlags      drop_flags      = 0;
        ImGuiInputTextFlags     flags           = 0;
        const char*             format          = "%.8lf";
        bool                    labelless       = true;
        double                  max             = 0.0;
        double                  min             = 0.0;
        double                  step            = 0.0;
        double                  step_fast       = 0.0;
    };

    bool    input(const char* label, double&, const input_double_t& opts={});
    bool    input(const char* label, unsigned, double*, const input_double_t& opts={});
    
    bool    input(const char* label, Quaternion3D&, const input_double_quaternion_t& opts={});
    bool    input(const char* label, RangeD&, const input_double_t& opts={});
    bool    input(const char* label, Size2D&, const input_double_t& opts={});
    bool    input(const char* label, Size3D&, const input_double_t& opts={});
    bool    input(const char* label, Size4D&, const input_double_t& opts={});
    bool    input(const char* label, UV2D&, const input_double_t& opts={});
    bool    input(const char* label, UVW3D&, const input_double_t& opts={});
    bool    input(const char* label, Vector1D&, const input_double_t& opts={});
    bool    input(const char* label, Vector2D&, const input_double_t& opts={});
    bool    input(const char* label, Vector3D&, const input_double_t& opts={});
    bool    input(const char* label, Vector4D&, const input_double_t& opts={});
}
