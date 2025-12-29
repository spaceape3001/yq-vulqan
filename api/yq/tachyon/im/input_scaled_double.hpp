////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/im/input_double.hpp>
#include <yq/unit/SCALED.hpp>

namespace yq::tachyon::im {
    template <typename DIM, double K>
    struct input_scaled_double_t {
        //const char*             drag            = nullptr;
        //ImGuiDragDropFlags      drag_flags      = 0;
        //string_view_vector_t    drop;
        //ImGuiDragDropFlags      drop_flags      = 0;
        ImGuiInputTextFlags     flags           = 0;
        const char*             format          = "%.6lf";
        bool                    labelless       = true;
        SCALED<double,DIM,K>         max             = { 0. };
        SCALED<double,DIM,K>         min             = { 0. };
        SCALED<double,DIM,K>         step            = { 0. };
        SCALED<double,DIM,K>         step_fast       = { 0. };
        
        constexpr operator input_double_t() const noexcept 
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
    bool input(const char* label, SCALED<double,DIM,K>&v, const input_scaled_double_t<DIM,K>& opts={})
    {
        return input(label, v.value, opts);
    }

    template <typename DIM, double K>
    bool input(const char* label, Vector1<SCALED<double,DIM,K>>&v, const input_scaled_double_t<DIM,K>& opts={})
    {
        return input(label, (double&) &v, opts);
    }

    template <typename DIM, double K>
    bool input(const char* label, Vector2<SCALED<double,DIM,K>>&v, const input_scaled_double_t<DIM,K>& opts={})
    {
        return input(label, 2, (double*) &v, opts);
    }

    template <typename DIM, double K>
    bool input(const char* label, Vector3<SCALED<double,DIM,K>>&v, const input_scaled_double_t<DIM,K>& opts={})
    {
        return input(label, 3, (double*) &v, opts);
    }

    template <typename DIM, double K>
    bool input(const char* label, Vector4<SCALED<double,DIM,K>>&v, const input_scaled_double_t<DIM,K>& opts={})
    {
        return input(label, 4, (double*) &v, opts);
    }
}
