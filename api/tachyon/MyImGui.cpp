////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <cstdint>

static_assert(sizeof(void*) == sizeof(uint64_t), "Breakage means ImGui textures will break (and we want text, right?)");

#include <tachyon/MyImGui.hpp>
#include "imgui_internal.h"
#include <yq/color/RGB.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/core/Any.hpp>
#include <yq/math/glm.hpp>
#include <yq/math/UV.hpp>
#include <yq/shape/Rectangle2.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/tensor/Tensor44.hpp>
#include <yq/vector/Vector3.hpp>

thread_local ImGuiContext* MyImGuiTLS   = nullptr;

namespace ImGui {
    ////////////////////////////////////////////////////////////////////////////

    bool    Checkbox(const char*z, bool&v)
    {
        return Checkbox(z, &v);
    }
    

    ////////////////////////////////////////////////////////////////////////////

    bool    ColorEdit(const char* label, yq::RGB3F&v, ImGuiColorEditFlags flags)
    {
        return ColorEdit3(label, &v.red, flags);
    }
    
    bool    ColorEdit(const char* label, yq::RGBA4F&v, ImGuiColorEditFlags flags)
    {
        return ColorEdit4(label, &v.red, flags);
    }

    ////////////////////////////////////////////////////////////////////////////

    bool    Combo(const char* label, int&v, const yq::EnumDef& edef, ImGuiComboFlags flags)
    {
        ImGuiContext& g = *GImGui;

        bool    value_changed   = false;
        std::string key(edef.key_of(v));
        if(!BeginCombo(label, key.c_str(), flags))
            return false;
        for(auto& itr : edef.name2val()){
            std::string la(itr.first);
            PushID(la.c_str());
            bool    item_selected   = v == itr.second;
            if(Selectable(la.c_str(), item_selected)){
                if(v != itr.second){
                    v       = itr.second;
                    value_changed   = true;
                }
            }
            if(item_selected)
                SetItemDefaultFocus();
            PopID();
        }
        EndCombo();
        if (value_changed)
            MarkItemEdited(g.LastItemData.ID);
        return value_changed;
    }

    ////////////////////////////////////////////////////////////////////////////

    bool    DragDouble(const char* label, double* v, const DragDoubleOptions& options)
    {
        return DragScalar(label, ImGuiDataType_Double, v, options.speed, &options.min, &options.max, options.format, options.flags );
    }
    
    bool    DragDouble(const char* label, double& v, const DragDoubleOptions& options)
    {
        return DragScalar(label, ImGuiDataType_Double, &v, options.speed, &options.min, &options.max, options.format, options.flags );
    }

    bool    DragDouble(const char* label, double*v, float v_speed, double v_min, double v_max, const char* format, ImGuiSliderFlags flags)
    {
        return DragScalar(label, ImGuiDataType_Double, v, v_speed, &v_min, &v_max, format, flags);
    }
    
    bool    DragDouble(const char* label, double&v, float v_speed, double v_min, double v_max, const char* format, ImGuiSliderFlags flags)
    {
        return DragScalar(label, ImGuiDataType_Double, &v, v_speed, &v_min, &v_max, format, flags);
    }
    
    bool    DragDouble2(const char* label, double v[2], float v_speed, double v_min, double v_max, const char* format, ImGuiSliderFlags flags)
    {
        return DragScalarN(label, ImGuiDataType_Double, v, 2, v_speed, &v_min, &v_max, format, flags);
    }

    bool    DragDouble2(const char* label, yq::Vector2D*v, float speed, double v_min, double v_max, const char* format, ImGuiSliderFlags flags)
    {
        return DragDouble2(label, (double*) v, speed, v_min, v_max, format, flags);
    }
    
    bool    DragDouble3(const char* label, double v[3], float v_speed, double v_min, double v_max, const char* format, ImGuiSliderFlags flags)
    {
        return DragScalarN(label, ImGuiDataType_Double, v, 3, v_speed, &v_min, &v_max, format, flags);
    }
    
    bool    DragDouble3(const char* label, yq::Vector3D*v, float speed, double v_min, double v_max, const char* format, ImGuiSliderFlags flags)
    {
        return DragDouble3(label, (double*) v, speed, v_min, v_max, format, flags);
    }
    
    bool    DragDouble4(const char* label, double v[4], float v_speed, double v_min, double v_max, const char* format, ImGuiSliderFlags flags)
    {
        return DragScalarN(label, ImGuiDataType_Double, v, 4, v_speed, &v_min, &v_max, format, flags);
    }
    
    bool    DragDouble4(const char* label, yq::Vector4D*v, float speed, double v_min, double v_max, const char* format, ImGuiSliderFlags flags)
    {
        return DragDouble4(label, (double*) v, speed, v_min, v_max, format, flags);
    }

    ////////////////////////////////////////////////////////////////////////////
    
    namespace {
        const void* stepptr(const InputDoubleOptions& options)
        {
            if(options.step > 0.)
                return &options.step;
            return nullptr;
        }

        const void* stepptr(const InputDoubleQuatOptions& options)
        {
            if(options.step > 0.)
                return &options.step;
            return nullptr;
        }

        const void* stepfastptr(const InputDoubleOptions& options)
        {
            if(options.step_fast > 0.)
                return &options.step_fast;
            return nullptr;
        }

        const void* stepfastptr(const InputDoubleQuatOptions& options)
        {
            if(options.step_fast > 0.)
                return &options.step_fast;
            return nullptr;
        }
    }

    bool    InputDouble(const char* label, double* v, const InputDoubleOptions& options)
    {   
        return InputDouble(label, v, options.step, options.step_fast, options.format, options.flags);
    }
    
    bool    InputDouble(const char* label, double& v, const InputDoubleOptions& options)
    {
        return InputDouble(label, &v, options.step, options.step_fast, options.format, options.flags);
    }

    bool    InputDouble(const char* label, yq::UV2D*v, const InputDoubleOptions& options)
    {
        return InputDouble2(label, (double*) v, options);
    }
    
    bool    InputDouble(const char* label, yq::UV2D&v, const InputDoubleOptions& options)
    {
        return InputDouble2(label, (double*) &v, options);
    }

    bool    InputDouble(const char* label, yq::Vector2D* v, const InputDoubleOptions& options)
    {
        return InputDouble2(label, (double*) v, options);
    }
    
    bool    InputDouble(const char* label, yq::Vector2D& v, const InputDoubleOptions& options)
    {
        return InputDouble2(label, (double*) &v, options);
    }
    
    bool    InputDouble(const char* label, yq::Vector3D* v, const InputDoubleOptions& options)
    {
        return InputDouble3(label, (double*) v, options);
    }
    
    bool    InputDouble(const char* label, yq::Vector3D& v, const InputDoubleOptions& options)
    {
        return InputDouble3(label, (double*) &v, options);
    }
    
    bool    InputDouble(const char* label, yq::Vector4D* v, const InputDoubleOptions& options)
    {
        return InputDouble4(label, (double*) v, options);
    }

    bool    InputDouble(const char* label, yq::Vector4D& v, const InputDoubleOptions& options)
    {
        return InputDouble4(label, (double*) &v, options);
    }
    
    bool    InputDouble(const char* label, yq::Quaternion3D*v, const InputDoubleQuatOptions& options)
    {
        return InputScalarN(label, ImGuiDataType_Double, v, 4, stepptr(options), stepfastptr(options), options.format, options.flags);
    }
    
    bool    InputDouble(const char* label, yq::Quaternion3D&v, const InputDoubleQuatOptions& options)
    {
        return InputScalarN(label, ImGuiDataType_Double, &v, 4, stepptr(options), stepfastptr(options), options.format, options.flags);
    }

    bool    InputDouble2(const char* label, double v[2], const InputDoubleOptions& options)
    {
        return InputScalarN(label, ImGuiDataType_Double, v, 2, stepptr(options), stepfastptr(options), options.format, options.flags);
    }
    
    bool    InputDouble3(const char* label, double v[3], const InputDoubleOptions& options)
    {
        return InputScalarN(label, ImGuiDataType_Double, v, 3, stepptr(options), stepfastptr(options), options.format, options.flags);
    }
    
    bool    InputDouble4(const char* label, double v[4], const InputDoubleOptions& options)
    {
        return InputScalarN(label, ImGuiDataType_Double, v, 4, stepptr(options), stepfastptr(options), options.format, options.flags);
    }


    ////////////////////////////////////////////////////////////////////////////

    namespace {
        const void* stepptr(const InputFloatOptions& options)
        {
            if(options.step > 0.)
                return &options.step;
            return nullptr;
        }

        const void* stepptr(const InputFloatQuatOptions& options)
        {
            if(options.step > 0.)
                return &options.step;
            return nullptr;
        }

        const void* stepfastptr(const InputFloatOptions& options)
        {
            if(options.step_fast > 0.)
                return &options.step_fast;
            return nullptr;
        }

        const void* stepfastptr(const InputFloatQuatOptions& options)
        {
            if(options.step_fast > 0.)
                return &options.step_fast;
            return nullptr;
        }
    }
    
    
    bool    InputFloat(const char* label, float*v, const InputFloatOptions& options)
    {
        return InputFloat(label, v, options.step, options.step_fast, options.format, options.flags);
    }
    
    bool    InputFloat(const char* label, float&v, const InputFloatOptions& options)
    {
        return InputFloat(label, &v, options.step, options.step_fast, options.format, options.flags);
    }

    bool    InputFloat(const char* label, yq::UV2F*v, const InputFloatOptions& options)
    {
        return InputFloat2(label, (float*) v, options);
    }
    
    bool    InputFloat(const char* label, yq::UV2F&v, const InputFloatOptions& options)
    {
        return InputFloat2(label, (float*) &v, options);
    }

    bool    InputFloat(const char* label, yq::Vector2F*v, const InputFloatOptions& options)
    {
        return InputFloat2(label, (float*) v, options);
    }
    
    bool    InputFloat(const char* label, yq::Vector2F&v, const InputFloatOptions& options)
    {
        return InputFloat2(label, (float*) &v, options);
    }

    bool    InputFloat(const char* label, yq::Vector3F*v, const InputFloatOptions& options)
    {
        return InputFloat3(label, (float*) v, options);
    }
    
    bool    InputFloat(const char* label, yq::Vector3F&v, const InputFloatOptions& options)
    {
        return InputFloat3(label, (float*) &v, options);
    }

    bool    InputFloat(const char* label, yq::Vector4F*v, const InputFloatOptions& options)
    {
        return InputFloat4(label, (float*) v, options);
    }
    
    bool    InputFloat(const char* label, yq::Vector4F&v, const InputFloatOptions& options)
    {
        return InputFloat4(label, (float*) &v, options);
    }

    bool    InputFloat(const char* label, yq::Quaternion3F*v, const InputFloatQuatOptions& options)
    {
        return InputScalarN(label, ImGuiDataType_Float, (float*) v, 4, stepptr(options), stepfastptr(options), options.format, options.flags);
    }
    
    bool    InputFloat(const char* label, yq::Quaternion3F&v, const InputFloatQuatOptions& options)
    {
        return InputScalarN(label, ImGuiDataType_Float, (float*) &v, 4, stepptr(options), stepfastptr(options), options.format, options.flags);
    }
    
    bool    InputFloat2(const char* label, float v[2], const InputFloatOptions& options)  
    {
        return InputScalarN(label, ImGuiDataType_Float, v, 2, stepptr(options), stepfastptr(options), options.format, options.flags);
    }
    
    bool    InputFloat3(const char* label, float v[3], const InputFloatOptions& options) 
    {
        return InputScalarN(label, ImGuiDataType_Float, v, 3, stepptr(options), stepfastptr(options), options.format, options.flags);
    }

    bool    InputFloat4(const char* label, float v[4], const InputFloatOptions& options)  
    {
        return InputScalarN(label, ImGuiDataType_Float, v, 4, stepptr(options), stepfastptr(options), options.format, options.flags);
    }

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


    void    Text(bool f)
    {
        TextUnformatted( f ? "true" : "false" );
    }

    void    Text(float v)
    {
        Text("%f", v);
    }
    
    void    Text(double v)
    {
        Text("%lf", v);
    }
    
    void    Text(uint64_t v)
    {
        Text("%ld", v);
    }

    void    Text(const yq::Any&v)
    {
        TextUnformatted(v.printable());
    }

    void    Text(const yq::Rectangle2D&v)
    {
        Text("{%lf × %lf @ (%+lf, %+lf)}", v.size.x, v.size.y, v.position.x, v.position.y );
    }

    void    Text(const yq::Size2D&v)
    {
        Text("{%lf × %lf}", v.x, v.y );
    }
    
    void    Text(const yq::Size2I&v)
    {
        Text("{%d × %d}", v.x, v.y );
    }

    void    Text(const yq::Tensor44D&v)
    {
        if(BeginTable("Tensor44D", 4, ImGuiTableFlags_BordersOuterV | ImGuiTableFlags_SizingFixedSame)){
            TableNextRow();
            TableNextColumn();
            Text("%lf", v.xx);
            TableNextColumn();
            Text("%lf", v.xy);
            TableNextColumn();
            Text("%lf", v.xz);
            TableNextColumn();
            Text("%lf", v.xw);

            TableNextRow();
            if(TableNextColumn())
                Text("%lf", v.yx);
            if(TableNextColumn())
                Text("%lf", v.yy);
            if(TableNextColumn())
                Text("%lf", v.yz);
            if(TableNextColumn())
                Text("%lf", v.yw);

            TableNextRow();
            if(TableNextColumn())
                Text("%lf", v.zx);
            if(TableNextColumn())
                Text("%lf", v.zy);
            if(TableNextColumn())
                Text("%lf", v.zz);
            if(TableNextColumn())
                Text("%lf", v.zw);

            TableNextRow();
            if(TableNextColumn())
                Text("%lf", v.wx);
            if(TableNextColumn())
                Text("%lf", v.wy);
            if(TableNextColumn())
                Text("%lf", v.wz);
            if(TableNextColumn())
                Text("%lf", v.ww);
            EndTable();
        }
    }
    
    void    Text(const yq::Vector2D&v)
    {
        Text("{%lf, %lf}", v.x, v.y );
    }
    
    void    Text(const yq::Vector2F&v)
    {
        Text("{%f, %f}", v.x, v.y );
    }

    void    Text(const yq::Vector3D&v)
    {
        Text("{%lf, %lf, %lf}", v.x, v.y, v.z);
    }

    void    Text(const yq::Vector4D&v)
    {
        Text("{%lf, %lf, %lf, %lf}", v.x, v.y, v.z, v.w);
    }

    void    Text(const glm::mat4&v)
    {
        if(BeginTable("glm::mat4", 4, ImGuiTableFlags_BordersOuterV | ImGuiTableFlags_SizingFixedSame)){
            TableNextRow();
            if(TableNextColumn())
                Text("%f", v[0][0]);
            if(TableNextColumn())
                Text("%f", v[0][1]);
            if(TableNextColumn())
                Text("%f", v[0][2]);
            if(TableNextColumn())
                Text("%f", v[0][3]);

            TableNextRow();
            if(TableNextColumn())
                Text("%f", v[1][0]);
            if(TableNextColumn())
                Text("%f", v[1][1]);
            if(TableNextColumn())
                Text("%f", v[1][2]);
            if(TableNextColumn())
                Text("%f", v[1][3]);

            TableNextRow();
            if(TableNextColumn())
                Text("%f", v[2][0]);
            if(TableNextColumn())
                Text("%f", v[2][1]);
            if(TableNextColumn())
                Text("%f", v[2][2]);
            if(TableNextColumn())
                Text("%f", v[2][3]);

            TableNextRow();
            if(TableNextColumn())
                Text("%f", v[3][0]);
            if(TableNextColumn())
                Text("%f", v[3][1]);
            if(TableNextColumn())
                Text("%f", v[3][2]);
            if(TableNextColumn())
                Text("%f", v[3][3]);
            EndTable();
        }
    }
    
    void    Text(const glm::dmat4&v)
    {
        if(BeginTable("glm::dmat4", 4, ImGuiTableFlags_BordersOuterV | ImGuiTableFlags_SizingFixedSame)){
            TableNextRow();
            if(TableNextColumn())
                Text("%lf", v[0][0]);
            if(TableNextColumn())
                Text("%lf", v[0][1]);
            if(TableNextColumn())
                Text("%lf", v[0][2]);
            if(TableNextColumn())
                Text("%lf", v[0][3]);

            TableNextRow();
            if(TableNextColumn())
                Text("%lf", v[1][0]);
            if(TableNextColumn())
                Text("%lf", v[1][1]);
            if(TableNextColumn())
                Text("%lf", v[1][2]);
            if(TableNextColumn())
                Text("%lf", v[1][3]);

            TableNextRow();
            if(TableNextColumn())
                Text("%lf", v[2][0]);
            if(TableNextColumn())
                Text("%lf", v[2][1]);
            if(TableNextColumn())
                Text("%lf", v[2][2]);
            if(TableNextColumn())
                Text("%lf", v[2][3]);

            TableNextRow();
            if(TableNextColumn())
                Text("%lf", v[3][0]);
            if(TableNextColumn())
                Text("%lf", v[3][1]);
            if(TableNextColumn())
                Text("%lf", v[3][2]);
            if(TableNextColumn())
                Text("%lf", v[3][3]);
            EndTable();
        }
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void    TextUnformatted(std::string_view sv)
    {
        if(sv.empty()){
            TextUnformatted("");
        } else {
            TextUnformatted(sv.data(), sv.data()+sv.size());
        }
    }
    
    ////////////////////////////////////////////////////////////////////////////

    // Taken from https://github.com/ocornut/imgui/issues/1537
    void ToggleSlider(const char* str_id, bool* v)
    {
        ImVec2 p = GetCursorScreenPos();
        ImDrawList* draw_list = GetWindowDrawList();

        float height = GetFrameHeight();
        float width = height * 1.55f;
        float radius = height * 0.50f;

        if (InvisibleButton(str_id, ImVec2(width, height)))
            *v = !*v;
        ImU32 col_bg;
        if (IsItemHovered())
            col_bg = *v ? IM_COL32(145+20, 211, 68+20, 255) : IM_COL32(218-20, 218-20, 218-20, 255);
        else
            col_bg = *v ? IM_COL32(145, 211, 68, 255) : IM_COL32(218, 218, 218, 255);

        draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);
        draw_list->AddCircleFilled(ImVec2(*v ? (p.x + width - radius) : (p.x + radius), p.y + radius), radius - 1.5f, IM_COL32(255, 255, 255, 255));
    }

    ////////////////////////////////////////////////////////////////////////////

    bool    VSliderDouble(const char* label, double* v, const VSliderDoubleOptions& options)
    {
        return VSliderScalar(label, options.size, ImGuiDataType_Double, v, &options.min, &options.max, options.format, options.flags);
    }
    
    bool    VSliderDouble(const char* label, double& v, const VSliderDoubleOptions& options)
    {
        return VSliderScalar(label, options.size, ImGuiDataType_Double, &v, &options.min, &options.max, options.format, options.flags);
    }
}
