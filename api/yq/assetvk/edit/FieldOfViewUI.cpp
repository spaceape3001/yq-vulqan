////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "FieldOfViewUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PFieldOfView.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::FieldOfViewUI)

namespace yq::tachyon {
    void FieldOfViewUI::init_meta()
    {
        auto w = writer<FieldOfViewUI>();
        w.description("UIEditor for FieldOfView");
        w.edits<PFieldOfView>();
        w.field("FOV", &FieldOfViewUI::fov);
    }
    
    FieldOfViewUI::FieldOfViewUI(UIFlags flags)
    {
    }
    
    FieldOfViewUI::FieldOfViewUI(const FieldOfViewUI& cp) : UIEditor(cp)
    {
    }
    
    FieldOfViewUI* FieldOfViewUI::clone() const
    {
        return new FieldOfViewUI(*this);
    }

    void    FieldOfViewUI::fov()
    {
        PFieldOfView* p   = snap()->proxy<PFieldOfView>();
        if(!p)
            return ;
            
        unit::Degree    v   = p->field_of_view();
        if(ImGui::Input("##fov", v))
            p -> field_of_view(SET, v);
    }
}
