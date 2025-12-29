////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/im/input_float.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon::im {
    template <typename DIM>
    struct input_mks_float_t {
        //const char*             drag            = nullptr;
        //ImGuiDragDropFlags      drag_flags      = 0;
        //string_view_vector_t    drop;
        //ImGuiDragDropFlags      drop_flags      = 0;
        ImGuiInputTextFlags     flags           = 0;
        const char*             format          = "%.3f";
        bool                    labelless       = true;
        MKS<float,DIM>         max             = { 0. };
        MKS<float,DIM>         min             = { 0. };
        MKS<float,DIM>         step            = { 0. };
        MKS<float,DIM>         step_fast       = { 0. };
        
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
    
    template <typename DIM>
    bool input(const char* label, MKS<float,DIM>&v, const input_mks_float_t<DIM>& opts={})
    {
        return input(label, v.value, opts);
    }

    template <typename DIM>
    bool input(const char* label, Vector1<MKS<float,DIM>>&v, const input_mks_float_t<DIM>& opts={})
    {
        return input(label, (float&) &v, opts);
    }

    template <typename DIM>
    bool input(const char* label, Vector2<MKS<float,DIM>>&v, const input_mks_float_t<DIM>& opts={})
    {
        return input(label, 2, (float*) &v, opts);
    }

    template <typename DIM>
    bool input(const char* label, Vector3<MKS<float,DIM>>&v, const input_mks_float_t<DIM>& opts={})
    {
        return input(label, 3, (float*) &v, opts);
    }

    template <typename DIM>
    bool input(const char* label, Vector4<MKS<float,DIM>>&v, const input_mks_float_t<DIM>& opts={})
    {
        return input(label, 4, (float*) &v, opts);
    }
}
