////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "FieldOfViewUI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/ui/UIEditorInfoWriter.hpp>
#include <tachyon/proxy/PFieldOfView.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::FieldOfViewUI)

namespace yq::tachyon {
    void FieldOfViewUI::init_info()
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
        if(ImGui::InputDouble("##fov", &v))
            p -> field_of_view(SET, v);
    }
}
