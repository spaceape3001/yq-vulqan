////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/im/input_double.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon::im {
    template <typename DIM>
    struct input_mks_double_t {
        //const char*             drag            = nullptr;
        //ImGuiDragDropFlags      drag_flags      = 0;
        //string_view_vector_t    drop;
        //ImGuiDragDropFlags      drop_flags      = 0;
        ImGuiInputTextFlags     flags           = 0;
        const char*             format          = "%.6lf";
        bool                    labelless       = true;
        MKS<double,DIM>         max             = { 0. };
        MKS<double,DIM>         min             = { 0. };
        MKS<double,DIM>         step            = { 0. };
        MKS<double,DIM>         step_fast       = { 0. };
        
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
    
    template <typename DIM>
    bool input(const char* label, MKS<double,DIM>&v, const input_mks_double_t<DIM>& opts={})
    {
        return input(label, v.value, opts);
    }

    template <typename DIM>
    bool input(const char* label, Vector1<MKS<double,DIM>>&v, const input_mks_double_t<DIM>& opts={})
    {
        return input(label, (double&) &v, opts);
    }

    template <typename DIM>
    bool input(const char* label, Vector2<MKS<double,DIM>>&v, const input_mks_double_t<DIM>& opts={})
    {
        return input(label, 2, (double*) &v, opts);
    }

    template <typename DIM>
    bool input(const char* label, Vector3<MKS<double,DIM>>&v, const input_mks_double_t<DIM>& opts={})
    {
        return input(label, 3, (double*) &v, opts);
    }

    template <typename DIM>
    bool input(const char* label, Vector4<MKS<double,DIM>>&v, const input_mks_double_t<DIM>& opts={})
    {
        return input(label, 4, (double*) &v, opts);
    }
}
