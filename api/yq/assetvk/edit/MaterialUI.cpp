////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaterialUI.hpp"
#include <yq/core/Result.hpp>
#include <yq/net/Url.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
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
        w.field("material", &MaterialUI::material);
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
        if(ImGui::InputText("##material", &v, ImGuiInputTextFlags_EnterReturnsTrue)){
            auto x  = to_url_view(v);
            if(x.good)
                p->material(SET, ::yq::copy(x.value));
        }
    }
}
