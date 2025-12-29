////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGBA.hpp>
#include <yq/color/RGB.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/typedef/vector1.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/typedef/vector3.hpp>
#include <yq/vector/Vector4.hpp>
#include <yq/tachyon/enum/UIFlags.hpp>

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

namespace yq::tachyon::imgui {
    using namespace ImGui;
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
        ImVec2              size    = { 40, 10 }; // main/other
    };

    bool    VSliderDouble(const char* label, double* v, const VSliderDoubleOptions& options={});
    bool    VSliderDouble(const char* label, double& v, const VSliderDoubleOptions& options={});
    
}
