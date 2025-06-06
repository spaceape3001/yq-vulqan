////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGBA.hpp>
#include <yq/color/RGB.hpp>
#include <yq/math/glm.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/typedef/quaternion3.hpp>
#include <yq/typedef/rgb.hpp>
#include <yq/typedef/rgba.hpp>
#include <yq/typedef/rectangle2.hpp>
#include <yq/typedef/tensor44.hpp>
#include <yq/units.hpp>
#include <yq/vector/Vector1.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/vector/Vector4.hpp>
#include <tachyon/enum/UIFlags.hpp>
#include <tachyon/typedef/texture.hpp>
#include <tachyon/api/ID.hpp>

#define IM_VEC2_CLASS_EXTRA                                                                 \
        constexpr ImVec2(const yq::Vector2D& v) : x((float) v.x), y((float) v.y) {}         \
        constexpr operator yq::Vector2D() const { return { x, y }; }                        \
        constexpr ImVec2(const yq::Vector2F& v) : x(v.x), y(v.y) {}                         \
        constexpr operator yq::Vector2F() const { return { x, y }; }                        \
        constexpr ImVec2(const yq::Size2D& v) : x((float) v.x), y((float) v.y) {}           \
        constexpr operator yq::Size2D() const { return { x, y }; }                          \
        constexpr ImVec2(const yq::Size2F& v) : x(v.x), y(v.y) {}                           \
        constexpr operator yq::Size2F() const { return { x, y }; }

#define IM_VEC4_CLASS_EXTRA                                                                                         \
        constexpr ImVec4(const yq::Vector4D& v) : x((float) v.x), y((float) v.y), z((float) v.z), w((float) v.w) {} \
        constexpr operator yq::Vector4D() const { return { x, y, z, w }; }                                          \
        constexpr ImVec4(const yq::Vector4F& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}                                 \
        constexpr operator yq::Vector4F() const { return { x, y, z, w }; }

#include "imgui.h"

/*
    This header file is covered by GPL-v3 (unless otherwise noted) and is used to 
    extend the ImGUI input controls to what we need.
*/
namespace ImGui {
    using yq::tachyon::UIFlag;
    using yq::tachyon::UIFlags;

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

    bool    ColorEdit(const char* label, yq::RGB3F&, ImGuiColorEditFlags flags=0);
    bool    ColorEdit(const char* label, yq::RGBA4F&, ImGuiColorEditFlags flags=0);

    bool    InputDouble2(const char* label, yq::Vector2D*, const char* format = "%.3lf", ImGuiInputTextFlags flags = 0);
    bool    InputDouble3(const char* label, yq::Vector3D*, const char* format = "%.3lf", ImGuiInputTextFlags flags = 0);
    bool    InputDouble4(const char* label, yq::Vector4D*, const char* format = "%.3fl", ImGuiInputTextFlags flags = 0);
    bool    InputDouble4(const char* label, yq::Quaternion3D*, const char* format = "%.4fl", ImGuiInputTextFlags flags = 0);
    
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
    
    
    #if 0
    
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
    
    void    TextUnformatted(std::string_view);
    
    void    Text(bool);
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

    ImGuiChildFlags_  ChildFlag(UIFlag flag);
    ImGuiChildFlags   ChildFlags(UIFlags flag);
    ImGuiWindowFlags_ WindowFlag(UIFlag flag);
    ImGuiWindowFlags  WindowFlags(UIFlags flag);
}
