////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Scene.hpp>
#include <yq/tachyon/api/SceneData.hpp>
#include <yq/tachyon/command/color/SetBgColorCommand.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/logging.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SceneUI)

namespace yq::tachyon {
    
    void SceneUI::init_meta()
    {
        auto w = writer<SceneUI>();
        w.field("Background Color", &SceneUI::bgcolor);
        w.edits<Scene>();
        
        //  TODO... the rendereds/lights/cameras
    }

    SceneUI::SceneUI(UIFlags flags) : UIEditor(flags)
    {
    }

    SceneUI::SceneUI(const SceneUI& cp) : UIEditor(cp)
    {
    }
    
    SceneUI::~SceneUI()
    {
    }
    
    SceneUI*  SceneUI::clone() const 
    {
        return new SceneUI(*this);
    }

    void    SceneUI::bgcolor()
    {
        const SceneSnap*    ss  = dynamic_cast<const SceneSnap*>(snap());
        if(!ss)
            return ;
        RGBA4F          v   = ss->bgcolor;
        if(ImGui::ColorEdit("##BgColor", v)){
            send(new SetBgColorCommand({.target=bound()}, v));
        }
    }
}
