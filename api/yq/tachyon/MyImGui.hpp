////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGBA.hpp>
#include <yq/color/RGB.hpp>
#include <yq/core/Enum.hpp>
#include <yq/core/Tristate.hpp>
#include <yq/math/glm.hpp>
#include <yq/shape/Size2.hpp>
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
#include <yq/units.hpp>
#include <yq/vector/Vector1.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/vector/Vector4.hpp>
#include <yq/tachyon/enum/UIFlags.hpp>
#include <yq/tachyon/typedef/texture.hpp>
#include <yq/tachyon/api/ID.hpp>

#define IM_VEC2_CLASS_EXTRA                                                                 \
        constexpr ImVec2(const yq::Vector2D& v) : x((float) v.x), y((float) v.y) {}         \
        constexpr explicit operator yq::Vector2D() const { return { x, y }; }               \
        constexpr ImVec2(const yq::Vector2F& v) : x(v.x), y(v.y) {}                         \
        constexpr explicit operator yq::Vector2F() const { return { x, y }; }               \
        constexpr ImVec2(const yq::Size2D& v) : x((float) v.x), y((float) v.y) {}           \
        constexpr explicit operator yq::Size2D() const { return { x, y }; }                 \
        constexpr ImVec2(const yq::Size2F& v) : x(v.x), y(v.y) {}                           \
        constexpr explicit operator yq::Size2F() const { return { x, y }; }

#define IM_VEC4_CLASS_EXTRA                                                                                         \
        constexpr ImVec4(const yq::Vector4D& v) : x((float) v.x), y((float) v.y), z((float) v.z), w((float) v.w) {} \
        constexpr operator yq::Vector4D() const { return { x, y, z, w }; }                                          \
        constexpr ImVec4(const yq::Vector4F& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}                                 \
        constexpr operator yq::Vector4F() const { return { x, y, z, w }; }                                          \
        constexpr ImVec4(const yq::RGB3F& v) : x(v.red), y(v.green), z(v.blue), w(0.) {}                            \
        constexpr explicit operator yq::RGB3F() const { return { x, y, z }; }                                       \
        constexpr ImVec4(const yq::RGBA4F& v) : x(v.red), y(v.green), z(v.blue), w(v.alpha) {}                      \
        constexpr explicit operator yq::RGBA4F() const { return { x, y, z, w }; }

#include "imgui.h"
#include "misc/cpp/imgui_stdlib.h"

namespace yq {
}
namespace yq::tachyon {
}

/*
    This header file is covered by GPL-v3 (unless otherwise noted) and is used to 
    extend the ImGUI input controls to what we need.
    
    TODO: Push into our own namespace...
*/
namespace ImGui {
    using yq::tachyon::UIFlag;
    using yq::tachyon::UIFlags;

    
    ImU32 Color(const yq::RGB3U8&);
    ImU32 Color(const yq::RGBA4U8&);
    ImU32 Color(const yq::RGBA4F&);
    ImU32 Color(const yq::RGB3F&);
    ImU32 Color(const ImVec4&);

    ImGuiChildFlags_        ChildFlag(UIFlag);
    ImGuiChildFlags         ChildFlags(UIFlags);
    ImGuiInputTextFlags_    TextFlag(UIFlag);
    ImGuiInputTextFlags     TextFlags(UIFlags);
    ImGuiWindowFlags_       WindowFlag(UIFlag);
    ImGuiWindowFlags        WindowFlags(UIFlags);
    
    
    //  For multiple defaulted parameters, we'll try to lean toward the structs

    ///////////////////////////
    //  TEXT
    ///////////////////////////

    enum class BrowseResult {
        None    = 0,
        Changed,
        Browse
    };
    
    BrowseResult BrowsableText(const char* id, std::string&, ImGuiInputTextFlags flags=0);


    ///////////////////////////
    //  CHECKBOXES
    ///////////////////////////

    #if 0 // From ImGui.h
    IMGUI_API bool          Checkbox(const char* label, bool* v);
    #endif

    bool    Checkbox(const char*, bool&);
    
    //! It'll cycle yes/no/maybe
    bool    Checkbox(const char*, yq::Tristate&);

    ///////////////////////////
    //  COLOR EDITS
    ///////////////////////////
    
    #if 0 // From ImGui.h
    IMGUI_API bool          ColorEdit3(const char* label, float col[3], ImGuiColorEditFlags flags = 0);
    IMGUI_API bool          ColorEdit4(const char* label, float col[4], ImGuiColorEditFlags flags = 0);
    #endif

    bool    ColorEdit(const char* label, yq::RGB3F&, ImGuiColorEditFlags flags=0);
    bool    ColorEdit(const char* label, yq::RGBA4F&, ImGuiColorEditFlags flags=0);

    ///////////////////////////
    //  COMBO BOXES
    ///////////////////////////

    #if 0 // From ImGui.h
    IMGUI_API bool          Combo(const char* label, int* current_item, const char* const items[], int items_count, int popup_max_height_in_items = -1);
    IMGUI_API bool          Combo(const char* label, int* current_item, const char* items_separated_by_zeros, int popup_max_height_in_items = -1);      // Separate items with \0 within a string, end item-list with \0\0. e.g. "One\0Two\0Three\0"
    IMGUI_API bool          Combo(const char* label, int* current_item, const char* (*getter)(void* user_data, int idx), void* user_data, int items_count, int popup_max_height_in_items = -1);
    #endif

    bool    Combo(const char*, int&, const yq::EnumDef&, ImGuiComboFlags flags=0);
    
    template <typename E>
    bool    Combo(const char* label, yq::EnumImpl<E>& e, ImGuiComboFlags flags=0)
    {
        int v   = e.value();
        bool f = Combo(label, v, *E::staticEnumInfo(), flags);
        if(f && v != e.value()){
            e   = (typename E::enum_t) v;
            return true;
        } else
            return false;
    }

    ///////////////////////////
    //  DRAG/SLIDERS
    ///////////////////////////

    #if 0 // From ImGui.h
    IMGUI_API bool          DragFloat(const char* label, float* v, float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", ImGuiSliderFlags flags = 0);     // If v_min >= v_max we have no bound
    IMGUI_API bool          DragFloat2(const char* label, float v[2], float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
    IMGUI_API bool          DragFloat3(const char* label, float v[3], float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
    IMGUI_API bool          DragFloat4(const char* label, float v[4], float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
    IMGUI_API bool          DragFloatRange2(const char* label, float* v_current_min, float* v_current_max, float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", const char* format_max = NULL, ImGuiSliderFlags flags = 0);
    IMGUI_API bool          DragInt(const char* label, int* v, float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d", ImGuiSliderFlags flags = 0);  // If v_min >= v_max we have no bound
    IMGUI_API bool          DragInt2(const char* label, int v[2], float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d", ImGuiSliderFlags flags = 0);
    IMGUI_API bool          DragInt3(const char* label, int v[3], float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d", ImGuiSliderFlags flags = 0);
    IMGUI_API bool          DragInt4(const char* label, int v[4], float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d", ImGuiSliderFlags flags = 0);
    IMGUI_API bool          DragIntRange2(const char* label, int* v_current_min, int* v_current_max, float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d", const char* format_max = NULL, ImGuiSliderFlags flags = 0);
    IMGUI_API bool          DragScalar(const char* label, ImGuiDataType data_type, void* p_data, float v_speed = 1.0f, const void* p_min = NULL, const void* p_max = NULL, const char* format = NULL, ImGuiSliderFlags flags = 0);
    IMGUI_API bool          DragScalarN(const char* label, ImGuiDataType data_type, void* p_data, int components, float v_speed = 1.0f, const void* p_min = NULL, const void* p_max = NULL, const char* format = NULL, ImGuiSliderFlags flags = 0);
    #endif

    struct DragDoubleOptions {
        ImGuiSliderFlags            flags   = 0;
        const char*                 format  = "%.3lf";
        double                      max     = 0.;
        double                      min     = 0.;
        float                       speed   = 1.0f;
    };

    bool    Drag(const char* label, double*, const DragDoubleOptions& options);
    bool    Drag(const char* label, double&, const DragDoubleOptions& options={});

    bool    Drag(const char* label, yq::Vector2D&, const DragDoubleOptions& options={});
    bool    Drag(const char* label, yq::Vector3D&, const DragDoubleOptions& options={});
    bool    Drag(const char* label, yq::Vector4D&, const DragDoubleOptions& options={});

    bool    Drag2(const char* label, double v[2], const DragDoubleOptions& options={});
    bool    Drag3(const char* label, double v[3], const DragDoubleOptions& options={});
    bool    Drag4(const char* label, double v[4], const DragDoubleOptions& options={});


    ///////////////////////////
    //  INPUTS (DOUBLES)
    ///////////////////////////

    #if 0 // From ImGui.h
    IMGUI_API bool          InputDouble(const char* label, double* v, double step = 0.0, double step_fast = 0.0, const char* format = "%.6f", ImGuiInputTextFlags flags = 0);
    #endif
    
    struct InputDoubleOptions {
        ImGuiInputTextFlags         flags       = 0;
        const char*                 format      = "%.6lf";
        double                      max         = 0.;
        double                      min         = 0.;
        double                      step        = 0.;
        double                      step_fast   = 0.;
    };

    struct InputDoubleQuatOptions {
        ImGuiInputTextFlags         flags       = 0;
        const char*                 format      = "%.8lf";
        double                      max         = 1.;
        double                      min         = -1.;
        double                      step        = 0.;
        double                      step_fast   = 0.;

        constexpr operator InputDoubleOptions() const noexcept
        {
            return { flags, format, max, min, step, step_fast };
        }
    };
    
    template <typename DIM>
    struct InputDoubleMKSOptions {
        ImGuiInputTextFlags         flags       = 0;
        const char*                 format      = "%.6lf";
        yq::MKS<double,DIM>         max         = { 0. };
        yq::MKS<double,DIM>         min         = { 0. };
        yq::MKS<double,DIM>         step        = { 0. };
        yq::MKS<double,DIM>         step_fast   = { 0. };

        constexpr operator InputDoubleOptions() const noexcept
        {
            return { flags, format, max.value, min.value, step.value, step_fast.value };
        }
    };

    template <typename DIM, double K>
    struct InputDoubleScaledOptions {
        ImGuiInputTextFlags         flags       = 0;
        const char*                 format      = "%.6lf";
        yq::SCALED<double,DIM,K>    max         = { 0. };
        yq::SCALED<double,DIM,K>    min         = { 0. };
        yq::SCALED<double,DIM,K>    step        = { 0. };
        yq::SCALED<double,DIM,K>    step_fast   = { 0. };

        constexpr operator InputDoubleOptions() const noexcept
        {
            return { flags, format, max.value, min.value, step.value, step_fast.value };
        }
    };

    bool    Input(const char* label, double* v, const InputDoubleOptions& options={});
    bool    Input(const char* label, double& v, const InputDoubleOptions& options={});

    bool    Input(const char* label, yq::Quaternion3D&, const InputDoubleQuatOptions& options={});
    bool    Input(const char* label, yq::RangeD&, const InputDoubleOptions& options={});
    bool    Input(const char* label, yq::Size2D&, const InputDoubleOptions& options={});
    bool    Input(const char* label, yq::Size3D&, const InputDoubleOptions& options={});
    bool    Input(const char* label, yq::Size4D&, const InputDoubleOptions& options={});
    bool    Input(const char* label, yq::UV2D&, const InputDoubleOptions& options={});
    bool    Input(const char* label, yq::UVW3D&, const InputDoubleOptions& options={});
    bool    Input(const char* label, yq::Vector1D&, const InputDoubleOptions& options={});
    bool    Input(const char* label, yq::Vector2D&, const InputDoubleOptions& options={});
    bool    Input(const char* label, yq::Vector3D&, const InputDoubleOptions& options={});
    bool    Input(const char* label, yq::Vector4D&, const InputDoubleOptions& options={});

    bool    Input2(const char* label, double v[2], const InputDoubleOptions& options={});
    bool    Input3(const char* label, double v[3], const InputDoubleOptions& options={});
    bool    Input4(const char* label, double v[4], const InputDoubleOptions& options={});

    template <typename DIM>
    bool    Input(const char* label, yq::MKS<double,DIM>& v, const InputDoubleMKSOptions<DIM>&options={})
    {
        return Input(label, &v.value, (InputDoubleOptions) options);
    }

    template <typename DIM>
    bool    Input(const char* label, yq::Vector2<yq::MKS<double,DIM>>& v, const InputDoubleMKSOptions<DIM>&options={})
    {
        return Input2(label, (double*) &v, (InputDoubleOptions) options);
    }

    template <typename DIM>
    bool    Input(const char* label, yq::Vector3<yq::MKS<double,DIM>>& v, const InputDoubleMKSOptions<DIM>&options={})
    {
        return Input3(label, (double*) &v, (InputDoubleOptions) options);
    }

    template <typename DIM>
    bool    Input(const char* label, yq::Vector4<yq::MKS<double,DIM>>& v, const InputDoubleMKSOptions<DIM>&options={})
    {
        return Input4(label, (double*) &v, (InputDoubleOptions) options);
    }

    template <typename DIM, double K>
    bool    Input(const char* label, yq::SCALED<double,DIM,K>& v, const InputDoubleScaledOptions<DIM,K>& options={})
    {
        return Input(label, &v.value, (InputDoubleOptions) options);
    }

    template <typename DIM, double K>
    bool    Input(const char* label, yq::Vector2<yq::SCALED<double,DIM,K>>& v, const InputDoubleScaledOptions<DIM,K>& options={})
    {
        return Input2(label, (double*) &v, (InputDoubleOptions) options);
    }

    template <typename DIM, double K>
    bool    Input(const char* label, yq::Vector3<yq::SCALED<double,DIM,K>>& v, const InputDoubleScaledOptions<DIM,K>& options={})
    {
        return Input3(label, (double*) &v, (InputDoubleOptions) options);
    }

    template <typename DIM, double K>
    bool    Input(const char* label, yq::Vector4<yq::SCALED<double,DIM,K>>& v, const InputDoubleScaledOptions<DIM,K>& options={})
    {
        return Input4(label, (double*) &v, (InputDoubleOptions) options);
    }

    ///////////////////////////
    //  INPUTS (FLOATS)
    ///////////////////////////

    #if 0 // From ImGui.h
    IMGUI_API bool          InputFloat(const char* label, float* v, float step = 0.0f, float step_fast = 0.0f, const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
    IMGUI_API bool          InputFloat2(const char* label, float v[2], const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
    IMGUI_API bool          InputFloat3(const char* label, float v[3], const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
    IMGUI_API bool          InputFloat4(const char* label, float v[4], const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
    #endif

    struct InputFloatOptions {
        ImGuiInputTextFlags         flags       = 0;
        const char*                 format      = "%.3f";
        float                       max         = 0.;
        float                       min         = 0.;
        float                       step        = 0.;
        float                       step_fast   = 0.;
    };

    struct InputFloatQuatOptions {
        ImGuiInputTextFlags         flags       = 0;
        const char*                 format      = "%.4f";
        float                       max         = 1.;
        float                       min         = -1.;
        float                       step        = 0.;
        float                       step_fast   = 0.;
        
        constexpr operator InputFloatOptions() const noexcept
        {
            return { flags, format, max, min, step, step_fast };
        }
    };
    
    template <typename DIM>
    struct InputFloatMKSOptions {
        ImGuiInputTextFlags         flags       = 0;
        const char*                 format      = "%.3f";
        yq::MKS<float,DIM>          max         = { 0.f };
        yq::MKS<float,DIM>          min         = { 0.f };
        yq::MKS<float,DIM>          step        = { 0.f };
        yq::MKS<float,DIM>          step_fast   = { 0.f };

        constexpr operator InputFloatOptions() const noexcept
        {
            return { flags, format, max.value, min.value, step.value, step_fast.value };
        }
    };

    template <typename DIM, double K>
    struct InputFloatScaledOptions {
        ImGuiInputTextFlags         flags       = 0;
        const char*                 format      = "%.3f";
        yq::MKS<float,DIM>          max         = { 0.f };
        yq::MKS<float,DIM>          min         = { 0.f };
        yq::SCALED<float,DIM,K>     step        = { 0.f };
        yq::SCALED<float,DIM,K>     step_fast   = { 0.f };

        constexpr operator InputFloatOptions() const noexcept
        {
            return { flags, format, max.value, min.value, step.value, step_fast.value };
        }
    };

    bool    Input(const char* label, float*, const InputFloatOptions& options);  
    bool    Input(const char* label, float&, const InputFloatOptions& options={});

    bool    Input2(const char* label, float[2], const InputFloatOptions& options);  
    bool    Input3(const char* label, float[3], const InputFloatOptions& options);  
    bool    Input4(const char* label, float[4], const InputFloatOptions& options);  

    bool    Input(const char* label, yq::RGB3F&, const InputFloatQuatOptions& options={});
    bool    Input(const char* label, yq::RGBA4F&, const InputFloatQuatOptions& options={});
    bool    Input(const char* label, yq::Quaternion3F&, const InputFloatQuatOptions& options={});
    bool    Input(const char* label, yq::Size2F&, const InputFloatOptions& options={});
    bool    Input(const char* label, yq::Size3F&, const InputFloatOptions& options={});
    bool    Input(const char* label, yq::Size4F&, const InputFloatOptions& options={});
    bool    Input(const char* label, yq::UV2F&, const InputFloatOptions& options={});
    bool    Input(const char* label, yq::UVW3F&, const InputFloatOptions& options={});
    bool    Input(const char* label, yq::Vector1F&, const InputFloatOptions& options={});
    bool    Input(const char* label, yq::Vector2F&, const InputFloatOptions& options={});
    bool    Input(const char* label, yq::Vector3F&, const InputFloatOptions& options={});
    bool    Input(const char* label, yq::Vector4F&, const InputFloatOptions& options={});

    template <typename DIM>
    bool    Input(const char* label, yq::MKS<float,DIM>& v, const InputFloatMKSOptions<DIM>&options={})
    {
        return Input(label, &v.value, InputFloatOptions{
            .flags      = options.flags,
            .format     = options.format,
            .max        = options.max.value,
            .min        = options.min.value,
            .step       = options.step.value,
            .step_fast  = options.step_fast.value
        });
    }

    template <typename DIM>
    bool    Input(const char* label, yq::Vector2<yq::MKS<float,DIM>>& v, const InputFloatMKSOptions<DIM>&options={})
    {
        return Input2(label, (float*) &v, InputFloatOptions{
            .flags      = options.flags,
            .format     = options.format,
            .max        = options.max.value,
            .min        = options.min.value,
            .step       = options.step.value,
            .step_fast  = options.step_fast.value
        });
    }

    template <typename DIM>
    bool    Input(const char* label, yq::Vector3<yq::MKS<float,DIM>>& v, const InputFloatMKSOptions<DIM>&options={})
    {
        return Input3(label, (float*) &v, InputFloatOptions{
            .flags      = options.flags,
            .format     = options.format,
            .max        = options.max.value,
            .min        = options.min.value,
            .step       = options.step.value,
            .step_fast  = options.step_fast.value
        });
    }

    template <typename DIM>
    bool    Input(const char* label, yq::Vector4<yq::MKS<float,DIM>>& v, const InputFloatMKSOptions<DIM>&options={})
    {
        return Input4(label, (float*) &v, InputFloatOptions{
            .flags      = options.flags,
            .format     = options.format,
            .max        = options.max.value,
            .min        = options.min.value,
            .step       = options.step.value,
            .step_fast  = options.step_fast.value
        });
    }

    template <typename DIM, double K>
    bool    Input(const char* label, yq::SCALED<float,DIM,K>& v, const InputFloatScaledOptions<DIM,K>& options={})
    {
        return Input(label, &v.value, InputFloatOptions{
            .flags      = options.flags,
            .format     = options.format,
            .max        = options.max.value,
            .min        = options.min.value,
            .step       = options.step.value,
            .step_fast  = options.step_fast.value
        });
    }
    
    template <typename DIM, double K>
    bool    Input(const char* label, yq::Vector2<yq::SCALED<float,DIM,K>>& v, const InputFloatScaledOptions<DIM,K>& options={})
    {
        return Input2(label, (float*) &v, InputFloatOptions{
            .flags      = options.flags,
            .format     = options.format,
            .step       = options.step.value,
            .step_fast  = options.step_fast.value
        });
    }

    template <typename DIM, double K>
    bool    Input(const char* label, yq::Vector3<yq::SCALED<float,DIM,K>>& v, const InputFloatScaledOptions<DIM,K>& options={})
    {
        return Input3(label, (float*) &v, InputFloatOptions{
            .flags      = options.flags,
            .format     = options.format,
            .max        = options.max.value,
            .min        = options.min.value,
            .step       = options.step.value,
            .step_fast  = options.step_fast.value
        });
    }

    template <typename DIM, double K>
    bool    Input(const char* label, yq::Vector4<yq::SCALED<float,DIM,K>>& v, const InputFloatScaledOptions<DIM,K>& options={})
    {
        return Input4(label, (float*) &v, InputFloatOptions{
            .flags      = options.flags,
            .format     = options.format,
            .max        = options.max.value,
            .min        = options.min.value,
            .step       = options.step.value,
            .step_fast  = options.step_fast.value
        });
    }

    ///////////////////////////
    //  INPUTS (UNSIGNED INTS)
    ///////////////////////////

    struct InputUnsignedOptions {
        ImGuiInputTextFlags         flags       = 0;
        const char*                 format      = "%d";
        unsigned                    step        = 0;
        unsigned                    step_fast   = 0;
    };
    
    bool    Input(const char* label, unsigned&, const InputUnsignedOptions& options={});
    bool    Input(const char* label, yq::Vector1U&, const InputUnsignedOptions& options={});
    bool    Input(const char* label, yq::Vector2U&, const InputUnsignedOptions& options={});
    bool    Input(const char* label, yq::Vector3U&, const InputUnsignedOptions& options={});
    bool    Input(const char* label, yq::Vector4U&, const InputUnsignedOptions& options={});

    bool    Input2(const char* label, unsigned[2], const InputUnsignedOptions& options);  
    bool    Input3(const char* label, unsigned[3], const InputUnsignedOptions& options);  
    bool    Input4(const char* label, unsigned[4], const InputUnsignedOptions& options);  


    ///////////////////////////
    //  Spacing
    ///////////////////////////

    //! Adds dummy space to get horizontal spacing to x value, returns the size necessary, negative means it's already
    //! Too far
    IMGUI_API float HorzDummyTo(float z);
    
    //! Adds dummy space to get vertical spacing to y value, returns the size necessary, negative means it's already
    //! Too far
    IMGUI_API float VertDummyTo(float y);

    #if 0
    ///////////////////////////
    //  SPINNERS (DISABLED)
    ///////////////////////////

    //  ============================================
    //  The following four are taken from https://github.com/ocornut/imgui/issues/2649
	IMGUI_API bool SpinScaler(const char* label, ImGuiDataType data_type, void* data_ptr, const void* step, const void* step_fast, const char* format, ImGuiInputTextFlags flags);
	IMGUI_API bool SpinInt(const char* label, int* v, int step = 1, int step_fast = 100, ImGuiInputTextFlags flags = 0);
	IMGUI_API bool SpinFloat(const char* label, float* v, float step = 0.0f, float step_fast = 0.0f, const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
	IMGUI_API bool SpinDouble(const char* label, double* v, double step = 0.0, double step_fast = 0.0, const char* format = "%.6f", ImGuiInputTextFlags flags = 0);
    //  ============================================
    
    template <typename DIM>
	bool SpinDouble(const char* label, yq::MKS<double,DIM>* v, yq::MKS<double,DIM> step = yq::ZERO, yq::MKS<double,DIM> step_fast = yq::ZERO, const char* format = "%.6f", ImGuiInputTextFlags flags = 0)
    {
        return SpinDouble(label, (double*) v, step.value, step_fast.value, format, flags);
    }

    template <typename DIM, double K>
	bool SpinDouble(const char* label, yq::SCALED<double,DIM,K>* v, yq::SCALED<double,DIM,K> step = yq::ZERO, yq::SCALED<double,DIM,K> step_fast = yq::ZERO, const char* format = "%.6f", ImGuiInputTextFlags flags = 0)
    {
        return SpinDouble(label, (double*) v, step.value, step_fast.value, format, flags);
    }
    #endif

    ///////////////////////////
    //  TEXT
    ///////////////////////////

    void    Text(bool);
    void    Text(int);
    void    Text(float);
    void    Text(double);
    void    Text(uint64_t);

    void    Text(const yq::Any&);
    void    Text(const yq::Rectangle2D&);
    void    Text(const yq::Size2D&);
    void    Text(const yq::Size2I&);
    void    Text(const yq::Tensor44D&);
    void    Text(const yq::Vector2D&);
    void    Text(const yq::Vector2F&);
    void    Text(const yq::Vector3D&);
    void    Text(const yq::Vector4D&);
    void    Text(const glm::mat4&);
    void    Text(const glm::dmat4&);

    void    TextUnformatted(std::string_view);

    ///////////////////////////
    //  Toggle Slider
    ///////////////////////////

    //! Renders a toggle-slider switch
    //! From https://github.com/ocornut/imgui/issues/1537
    void    ToggleSlider(const char* str_id, bool* v);
    
    
    ///////////////////////////
    //  Vertical Slider
    ///////////////////////////

    #if 0 // From ImGui.h
    IMGUI_API bool          VSliderFloat(const char* label, const ImVec2& size, float* v, float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
    IMGUI_API bool          VSliderInt(const char* label, const ImVec2& size, int* v, int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0);
    IMGUI_API bool          VSliderScalar(const char* label, const ImVec2& size, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format = NULL, ImGuiSliderFlags flags = 0);
    #endif

    struct VSliderDoubleOptions {
        ImGuiSliderFlags    flags   = 0;
        const char*         format  = "%.3lf";
        double              max     = 0.;
        double              min     = 0.;
        ImVec2              size    = { 40, 10 };
    };

    bool    VSliderDouble(const char* label, double* v, const VSliderDoubleOptions& options={});
    bool    VSliderDouble(const char* label, double& v, const VSliderDoubleOptions& options={});
    
}
