////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <math/Vector2.hpp>
#include <math/Vector4.hpp>
#include <math/preamble.hpp>
#include <math/MKS.hpp>
#include <math/SCALED.hpp>
#include <math/RGBA.hpp>
#include <math/RGB.hpp>

#define IM_VEC2_CLASS_EXTRA                                                                 \
        constexpr ImVec2(const yq::Vector2D& v) : x((float) v.x), y((float) v.y) {}         \
        constexpr operator yq::Vector2D() const { return { x, y }; }                        \
        constexpr ImVec2(const yq::Vector2F& v) : x(v.x), y(v.y) {}                         \
        constexpr operator yq::Vector2F() const { return { x, y }; }

#define IM_VEC4_CLASS_EXTRA                                                                                         \
        constexpr ImVec4(const yq::Vector4D& v) : x((float) v.x), y((float) v.y), z((float) v.z), w((float) v.w) {} \
        constexpr operator yq::Vector4D() const { return { x, y, z, w }; }                                          \
        constexpr ImVec4(const yq::Vector4F& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}                                 \
        constexpr operator yq::Vector4F() const { return { x, y, z, w }; }

#include <imgui.h>

/*
    This header file is covered by GPL-v3 (unless otherwise noted) and is used to 
    extend the ImGUI input controls to what we need.
*/
namespace ImGui {
    bool    Checkbox(const char*, bool&);
    bool    DragDouble(const char* label, double*, float speed, double v_min=0.0, double v_max=0.0, const char* format="%.3lf", ImGuiSliderFlags flags=0);
    bool    DragDouble(const char* label, double&, float speed, double v_min=0.0, double v_max=0.0, const char* format="%.3lf", ImGuiSliderFlags flags=0);
    bool    DragDouble2(const char* label, double v[2], float speed, double v_min=0.0, double v_max=0.0, const char* format="%.3lf", ImGuiSliderFlags flags=0);
    bool    DragDouble3(const char* label, double v[3], float speed, double v_min=0.0, double v_max=0.0, const char* format="%.3lf", ImGuiSliderFlags flags=0);
    bool    DragDouble4(const char* label, double v[4], float speed, double v_min=0.0, double v_max=0.0, const char* format="%.3lf", ImGuiSliderFlags flags=0);

    bool    InputDouble2(const char* label, double v[2], const char* format = "%.3lf", ImGuiInputTextFlags flags = 0);
    bool    InputDouble3(const char* label, double v[3], const char* format = "%.3lf", ImGuiInputTextFlags flags = 0);
    bool    InputDouble4(const char* label, double v[4], const char* format = "%.3fl", ImGuiInputTextFlags flags = 0);

    //! Renders a toggle-slider switch
    //! From https://github.com/ocornut/imgui/issues/1537
    void    ToggleButton(const char* str_id, bool* v);

    bool    VSliderDouble(const char* label, const ImVec2& size, double* v, double v_min, double v_max, const char* format = "%.l3f", ImGuiSliderFlags flags = 0);
    bool    VSliderDouble(const char* label, const ImVec2& size, double& v, double v_min, double v_max, const char* format = "%.l3f", ImGuiSliderFlags flags = 0);


    bool    DragDouble2(const char* label, yq::Vector2D*, float speed, double v_min=0.0, double v_max=0.0, const char* format="%.3lf", ImGuiSliderFlags flags=0);
    bool    DragDouble3(const char* label, yq::Vector3D*, float speed, double v_min=0.0, double v_max=0.0, const char* format="%.3lf", ImGuiSliderFlags flags=0);
    bool    DragDouble4(const char* label, yq::Vector4D*, float speed, double v_min=0.0, double v_max=0.0, const char* format="%.3lf", ImGuiSliderFlags flags=0);

    bool    InputDouble2(const char* label, yq::Vector2D*, const char* format = "%.3lf", ImGuiInputTextFlags flags = 0);
    bool    InputDouble3(const char* label, yq::Vector3D*, const char* format = "%.3lf", ImGuiInputTextFlags flags = 0);
    bool    InputDouble4(const char* label, yq::Vector4D*, const char* format = "%.3fl", ImGuiInputTextFlags flags = 0);
    bool    InputDouble4(const char* label, yq::Quaternion3D*, const char* format = "%.3fl", ImGuiInputTextFlags flags = 0);
    
    template <typename DIM>
    bool    InputDouble(const char* label, yq::MKS<double,DIM>* v, yq::MKS<double,DIM> step = { 0.0 }, yq::MKS<double,DIM> step_fast = { 0.0 }, const char* format = "%.6f", ImGuiInputTextFlags flags = 0)
    {
        return InputDouble(label, (double*) v, step.value, step_fast.value, format, flags);
    }

    template <typename DIM, double K>
    bool    InputDouble(const char* label, yq::SCALED<double,DIM,K>* v, yq::SCALED<double,DIM,K> step = { 0.0 }, yq::SCALED<double,DIM,K> step_fast = { 0.0 }, const char* format = "%.6f", ImGuiInputTextFlags flags = 0)
    {
        return InputDouble(label, (double*) v, step.value, step_fast.value, format, flags);
    }

    template <typename DIM>
    bool    InputDouble2(const char* label, yq::Vector2<yq::MKS<double,DIM>>* v, const char* format = "%.6f", ImGuiInputTextFlags flags = 0)
    {
        return InputDouble2(label, (double*) v, format, flags);
    }

    template <typename DIM>
    bool    InputDouble3(const char* label, yq::Vector3<yq::MKS<double,DIM>>* v, const char* format = "%.6f", ImGuiInputTextFlags flags = 0)
    {
        return InputDouble3(label, (double*) v, format, flags);
    }

    template <typename DIM>
    bool    InputDouble4(const char* label, yq::Vector4<yq::MKS<double,DIM>>* v, const char* format = "%.6f", ImGuiInputTextFlags flags = 0)
    {
        return InputDouble4(label, (double*) v, format, flags);
    }
    
    inline constexpr ImU32 Color(const yq::RGB3U8& clr)
    {
        return IM_COL32(clr.red, clr.green, clr.blue, 255);
    }

}

