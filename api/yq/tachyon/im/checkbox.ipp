////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "checkbox.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include "imgui_internal.h"

namespace yq::tachyon::im {

    #if 0 // From ImGui.h
    IMGUI_API bool          Checkbox(const char* label, bool* v);
    #endif

    bool    checkbox(const char*z, bool&v)
    {
        return ImGui::Checkbox(z, &v);
    }
    
    bool    checkbox(const char*label, Tristate&v)
    {
        bool    checked   = v == Tristate::Yes;
        
        ImGui::PushItemFlag(ImGuiItemFlags_MixedValue, v == Tristate::Maybe);
        bool    ret     = ImGui::Checkbox(label, &checked);
        ImGui::PopItemFlag();
        if(ret){
            switch(v){
            case Tristate::Yes:
                v = Tristate::No;
                break;
            case Tristate::No:
                v   = Tristate::Maybe;
                break;
            case Tristate::Maybe:
                v   = Tristate::Yes;
                break;
            }
        }
        return ret;
    }
}
