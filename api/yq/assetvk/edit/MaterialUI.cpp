////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaterialUI.hpp"
#include <yq/core/Result.hpp>
#include <yq/net/Url.hpp>
#include <yq/assetvk/gesture/file/PickMaterialFileGesture.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/command/material/SetMaterialSpecCommand.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PMaterial.hpp>
#include <misc/cpp/imgui_stdlib.h>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaterialUI)

namespace yq::tachyon {
    void MaterialUI::init_meta()
    {
        auto w = writer<MaterialUI>();
        w.description("UIEditor for Material");
        w.edits<PMaterial>();
        w.field("Material", &MaterialUI::material);
    }
    
    MaterialUI::MaterialUI(UIFlags flags)
    {
    }
    
    MaterialUI::MaterialUI(const MaterialUI& cp) : UIEditor(cp)
    {
    }
    
    MaterialUI* MaterialUI::clone() const
    {
        return new MaterialUI(*this);
    }

    void    MaterialUI::material()
    {
        PMaterial* p   = snap()->proxy<PMaterial>();
        if(!p)
            return ;
        
        std::string     v = to_string(p->material(URL));
        switch(ImGui::BrowsableText("##material", v, ImGuiInputTextFlags_EnterReturnsTrue)){
        case ImGui::BrowseResult::None:
            break;
        case ImGui::BrowseResult::Changed:
            send(new SetMaterialSpecCommand({.target=snap()->self}, v));
            break;
        case ImGui::BrowseResult::Browse:
            gesture(new PickMaterialFileGesture(snap()->self));
            break;
        }
    }
}
