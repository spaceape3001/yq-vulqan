////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MeshUI.hpp"
#include <yq/core/Result.hpp>
#include <yq/net/Url.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/command/mesh/SetMeshSpecCommand.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PMesh.hpp>
#include <misc/cpp/imgui_stdlib.h>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MeshUI)

namespace yq::tachyon {
    void MeshUI::init_meta()
    {
        auto w = writer<MeshUI>();
        w.description("UIEditor for Mesh");
        w.edits<PMesh>();
        w.field("Mesh", &MeshUI::mesh);
    }
    
    MeshUI::MeshUI(UIFlags flags)
    {
    }
    
    MeshUI::MeshUI(const MeshUI& cp) : UIEditor(cp)
    {
    }
    
    MeshUI* MeshUI::clone() const
    {
        return new MeshUI(*this);
    }

    void    MeshUI::mesh()
    {
        PMesh* p   = snap()->proxy<PMesh>();
        if(!p)
            return ;
        
        std::string     v = to_string(p->mesh(URL));
        ImGui::SetNextItemWidth(-1);
        if(ImGui::InputText("##mesh", &v, ImGuiInputTextFlags_EnterReturnsTrue))
            send(new SetMeshSpecCommand({.target=snap()->self}, v));
    }
}
