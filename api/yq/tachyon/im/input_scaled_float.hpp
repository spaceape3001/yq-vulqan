////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/im/input_float.hpp>
#include <yq/unit/SCALED.hpp>

namespace yq::tachyon::im {
    template <typename DIM, double K>
    struct input_scaled_float_t {
        //const char*             drag            = nullptr;
        //ImGuiDragDropFlags      drag_flags      = 0;
        //string_view_vector_t    drop;
        //ImGuiDragDropFlags      drop_flags      = 0;
        ImGuiInputTextFlags     flags           = 0;
        const char*             format          = "%.3f";
        bool                    labelless       = true;
        SCALED<float,DIM,K>         max             = { 0. };
        SCALED<float,DIM,K>         min             = { 0. };
        SCALED<float,DIM,K>         step            = { 0. };
        SCALED<float,DIM,K>         step_fast       = { 0. };
        
        constexpr operator input_float_t() const noexcept 
        {
            return {
                .flags      = flags,
                .format     = format,
                .labelless  = labelless,
                .max        = max.value,
                .min        = min.value,
                .step       = step.value,
                .step_fast  = step_fast.value
            };
        }
    };    
    
    template <typename DIM, double K>
    bool input(const char* label, SCALED<float,DIM,K>&v, const input_scaled_float_t<DIM,K>& opts={})
    {
        return input(label, v.value, opts);
    }

    template <typename DIM, double K>
    bool input(const char* label, Vector1<SCALED<float,DIM,K>>&v, const input_scaled_float_t<DIM,K>& opts={})
    {
        return input(label, (float&) &v, opts);
    }

    template <typename DIM, double K>
    bool input(const char* label, Vector2<SCALED<float,DIM,K>>&v, const input_scaled_float_t<DIM,K>& opts={})
    {
        return input(label, 2, (float*) &v, opts);
    }

    template <typename DIM, double K>
    bool input(const char* label, Vector3<SCALED<float,DIM,K>>&v, const input_scaled_float_t<DIM,K>& opts={})
    {
        return input(label, 3, (float*) &v, opts);
    }

    template <typename DIM, double K>
    bool input(const char* label, Vector4<SCALED<float,DIM,K>>&v, const input_scaled_float_t<DIM,K>& opts={})
    {
        return input(label, 4, (float*) &v, opts);
    }
}
