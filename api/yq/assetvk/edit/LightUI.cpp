////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LightUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Light.hpp>
#include <yq/tachyon/api/LightData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/command/light/LightColorCommand.hpp>
#include <yq/tachyon/command/light/LightIntensityCommand.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LightUI)

namespace yq::tachyon {
    void LightUI::init_meta()
    {
        auto w = writer<LightUI>();
        w.description("UIEditor for Color");
        w.edits<Light>();
        w.field("Color", &LightUI::color);
        w.field("Intensity", &LightUI::intensity);
    }
    
    LightUI::LightUI(UIFlags flags)
    {
    }
    
    LightUI::LightUI(const LightUI& cp) : UIEditor(cp)
    {
    }
    
    LightUI* LightUI::clone() const
    {
        return new LightUI(*this);
    }

//                send(new SetNameCommand({.target=sn->self}, std::string(text)));

    void    LightUI::color()
    {
        const LightSnap*    sn  = dynamic_cast<const LightSnap*>(snap());
        if(!sn)
            return;
        RGB3F   v   = sn->color;
        if(ImGui::ColorEdit("##color", v))
            send(new LightColorCommand({.target=sn->self}, v));
    }

    void    LightUI::intensity()
    {
        const LightSnap*    sn  = dynamic_cast<const LightSnap*>(snap());
        if(!sn)
            return;
        float   v   = sn->intensity;
        if(ImGui::InputFloat("##intensity", &v))
            send(new LightIntensityCommand({.target=sn->self}, v));
    }
    
}

