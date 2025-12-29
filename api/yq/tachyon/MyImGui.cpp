////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <cstdint>

#include "MyImGui.hpp"

#include "imgui_internal.h"
#include <yq/color/RGB.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/vector/Vector4.hpp>

thread_local ImGuiContext* MyImGuiTLS   = nullptr;

namespace ImGui {

    ////////////////////////////////////////////////////////////////////////////

    ImU32 Color(const ImVec4& clr)
    {
        return GetColorU32(clr);
    }

    ImU32 Color(const yq::RGB3U8& clr)
    {
        return IM_COL32(clr.red, clr.green, clr.blue, 255);
    }

    ImU32 Color(const yq::RGBA4U8& clr)
    {
        return IM_COL32(clr.red, clr.green, clr.blue, clr.alpha);
    }

    ImU32 Color(const yq::RGBA4F& clr)
    {
        return GetColorU32(clr);
    }
    
    ImU32 Color(const yq::RGB3F& clr)
    {
        return GetColorU32({ clr.red, clr.green, clr.blue, 1. });
    }

#if 0
    ////////////////////////////////////////////////////////////////////////////

    bool    Drag(const char* label, double*v, const DragDoubleOptions& options)
    {
        return DragScalar(label, ImGuiDataType_Double, v, options.speed, &options.min, &options.max, options.format, options.flags );
    }
    
    bool    Drag(const char* label, double&v, const DragDoubleOptions& options)
    {
        return DragScalar(label, ImGuiDataType_Double, &v, options.speed, &options.min, &options.max, options.format, options.flags );
    }
    

    bool    Drag(const char* label, yq::Vector2D&v, const DragDoubleOptions& options)
    {
        return Drag2(label, (double*) &v, options);
    }
    
    bool    Drag(const char* label, yq::Vector3D&v, const DragDoubleOptions& options)
    {
        return Drag3(label, (double*) &v, options);
    }
    
    bool    Drag(const char* label, yq::Vector4D&v, const DragDoubleOptions& options)
    {
        return Drag4(label, (double*) &v, options);
    }

    bool    Drag2(const char* label, double v[2], const DragDoubleOptions& options)
    {
        return DragScalarN(label, ImGuiDataType_Double, v, 2, options.speed, &options.min, &options.max, options.format, options.flags);
    }
    
    bool    Drag3(const char* label, double v[3], const DragDoubleOptions& options)
    {
        return DragScalarN(label, ImGuiDataType_Double, v, 3, options.speed, &options.min, &options.max, options.format, options.flags);
    }
    
    bool    Drag4(const char* label, double v[4], const DragDoubleOptions& options)
    {
        return DragScalarN(label, ImGuiDataType_Double, v, 4, options.speed, &options.min, &options.max, options.format, options.flags);
    }


#endif

    ////////////////////////////////////////////////////////////////////////////


    //  ============================================
    //  https://github.com/ocornut/imgui/issues/2649
    #if 0
    bool SpinScaler(const char* label, ImGuiDataType data_type, void* data_ptr, const void* step, const void* step_fast, const char* format, ImGuiInputTextFlags flags)
    {
        ImGuiWindow* window = GetCurrentWindow();
        if(!window)
            return false;
            
        if (window->SkipItems)
            return false;
        const ImGuiID id = window->GetID(label);

        ImGuiContext& g = *GImGui;
        ImGuiStyle& style = g.Style;

        if (format == NULL)
            format = DataTypeGetInfo(data_type)->PrintFmt;

        char buf[64];
        DataTypeFormatString(buf, IM_ARRAYSIZE(buf), data_type, data_ptr, format);

        bool value_changed = false;
        if ((flags & (ImGuiInputTextFlags_CharsHexadecimal | ImGuiInputTextFlags_CharsScientific)) == 0)
            flags |= ImGuiInputTextFlags_CharsDecimal;
        flags |= ImGuiInputTextFlags_AutoSelectAll;
        //flags |= ImGuiInputTextFlags_NoMarkEdited;  // We call MarkItemEdited() ourselve by comparing the actual data rather than the string.

        if (step != NULL)
        {
            const float button_size = GetFrameHeight();

            BeginGroup(); // The only purpose of the group here is to allow the caller to query item data e.g. IsItemActive()
            PushID(label);
            SetNextItemWidth(ImMax(1.0f, CalcItemWidth() - (button_size + style.ItemInnerSpacing.x) * 2));
            if (InputText("", buf, IM_ARRAYSIZE(buf), flags)) // PushId(label) + "" gives us the expected ID from outside point of view
                value_changed = DataTypeApplyFromText(buf, data_type, data_ptr, format, g.InputTextState.InitialTextA.Data);

            // Step buttons
            const ImVec2 backup_frame_padding = style.FramePadding;
            style.FramePadding.x = style.FramePadding.y;
            ImGuiButtonFlags button_flags = ImGuiButtonFlags_Repeat | ImGuiButtonFlags_DontClosePopups;
            if (flags & ImGuiInputTextFlags_ReadOnly)
                button_flags |= ImGuiItemFlags_Disabled;
            SameLine(0, style.ItemInnerSpacing.x);

    // start diffs
            float frame_height = GetFrameHeight();
            float arrow_size = std::floor(frame_height * .45f);
            float arrow_spacing = frame_height - 2.0f * arrow_size;

            BeginGroup();
            PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{g.Style.ItemSpacing.x, arrow_spacing});

            // save/change font size to draw arrow buttons correctly
            float org_font_size = GetDrawListSharedData()->FontSize;
            GetDrawListSharedData()->FontSize = arrow_size;

            if (ArrowButtonEx("+", ImGuiDir_Up, ImVec2(arrow_size, arrow_size), button_flags))
            {
                DataTypeApplyOp(data_type, '+', data_ptr, data_ptr, g.IO.KeyCtrl && step_fast ? step_fast : step);
                value_changed = true;
            }

            if (ArrowButtonEx("-", ImGuiDir_Down, ImVec2(arrow_size, arrow_size), button_flags))
            {
                DataTypeApplyOp(data_type, '-', data_ptr, data_ptr, g.IO.KeyCtrl && step_fast ? step_fast : step);
                value_changed = true;
            }

            // restore font size
            GetDrawListSharedData()->FontSize = org_font_size;

            PopStyleVar(1);
            EndGroup();
    // end diffs

            const char* label_end = FindRenderedTextEnd(label);
            if (label != label_end)
            {
                SameLine(0, style.ItemInnerSpacing.x);
                TextEx(label, label_end);
            }
            style.FramePadding = backup_frame_padding;

            PopID();
            EndGroup();
        }
        else
        {
            if (InputText(label, buf, IM_ARRAYSIZE(buf), flags))
                value_changed = DataTypeApplyFromText(buf, data_type, data_ptr, format, g.InputTextState.InitialTextA.Data);
        }
        if (value_changed)
            MarkItemEdited(id);

        return value_changed;
    }

    bool SpinInt(const char* label, int* v, int step, int step_fast, ImGuiInputTextFlags flags)
    {
        // Hexadecimal input provided as a convenience but the flag name is awkward. Typically you'd use InputText() to parse your own data, if you want to handle prefixes.
        const char* format = (flags & ImGuiInputTextFlags_CharsHexadecimal) ? "%08X" : "%d";
        return SpinScaler(label, ImGuiDataType_S32, (void*)v, (void*)(step>0 ? &step : NULL), (void*)(step_fast>0 ? &step_fast : NULL), format, flags);
    }

    bool SpinFloat(const char* label, float* v, float step, float step_fast, const char* format, ImGuiInputTextFlags flags)
    {
        flags |= ImGuiInputTextFlags_CharsScientific;
        return SpinScaler(label, ImGuiDataType_Float, (void*)v, (void*)(step>0.0f ? &step : NULL), (void*)(step_fast>0.0f ? &step_fast : NULL), format, flags);
    }

    bool SpinDouble(const char* label, double* v, double step, double step_fast, const char* format, ImGuiInputTextFlags flags)
    {
        flags |= ImGuiInputTextFlags_CharsScientific;
        return SpinScaler(label, ImGuiDataType_Double, (void*)v, (void*)(step>0.0 ? &step : NULL), (void*)(step_fast>0.0 ? &step_fast : NULL), format, flags);
    }
    #endif


    ////////////////////////////////////////////////////////////////////////////
#if 0
    bool    VSliderDouble(const char* label, double* v, const VSliderDoubleOptions& options)
    {
        return VSliderScalar(label, options.size, ImGuiDataType_Double, v, &options.min, &options.max, options.format, options.flags);
    }
    
    bool    VSliderDouble(const char* label, double& v, const VSliderDoubleOptions& options)
    {
        return VSliderScalar(label, options.size, ImGuiDataType_Double, &v, &options.min, &options.max, options.format, options.flags);
    }
#endif
}
