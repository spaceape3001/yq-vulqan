////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "combo_enum.hpp"
#include "imgui_internal.h"

namespace yq::tachyon::im {
    bool    combo(const char* label, int&v, const yq::EnumDef& edef, const combo_options_t& opts)
    {
        ImGuiContext& g = *GImGui;

        bool    value_changed   = false;
        std::string key(edef.key_of(v));
        if(opts.labelless)
            ImGui::SetNextItemWidth(-1);
        if(!ImGui::BeginCombo(label, key.c_str(), opts.flags))
            return false;
        for(auto& itr : edef.name2val()){
            std::string_view    disp    = edef.display_of(itr.second);
            std::string la = std::format("{}##{}", disp, itr.first);
            ImGui::PushID(la.c_str());
            bool    item_selected   = v == itr.second;
            if(ImGui::Selectable(la.c_str(), item_selected)){
                if(v != itr.second){
                    v       = itr.second;
                    value_changed   = true;
                }
            }
            if(item_selected)
                ImGui::SetItemDefaultFocus();
            ImGui::PopID();
        }
        ImGui::EndCombo();
        if (value_changed)
            ImGui::MarkItemEdited(g.LastItemData.ID);
        return value_changed;
    }

    bool    combo(const char* label, int& v, const yq::EnumerationInfo& edef, const combo_options_t& opts)
    {
        ImGuiContext& g = *GImGui;

        bool    value_changed   = false;
        std::string key(edef.display(v));
        if(opts.labelless)
            ImGui::SetNextItemWidth(-1);
        if(!ImGui::BeginCombo(label, key.c_str(), opts.flags))
            return false;
        for(int ev : edef.values(UNIQUE)){
            std::string la = std::format("{}##{}", edef.display(ev), edef.key(ev));
            ImGui::PushID(la.c_str());
            bool    item_selected   = v == ev;
            if(ImGui::Selectable(la.c_str(), item_selected)){
                if(v != ev){
                    v       = ev;
                    value_changed   = true;
                }
            }
            if(item_selected)
                ImGui::SetItemDefaultFocus();
            ImGui::PopID();
        }
        ImGui::EndCombo();
        if (value_changed)
            ImGui::MarkItemEdited(g.LastItemData.ID);
        return value_changed;
    }
    
}

