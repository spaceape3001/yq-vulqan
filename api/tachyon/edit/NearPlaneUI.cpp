////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "NearPlaneUI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/ui/UIEditorInfoWriter.hpp>
#include <tachyon/proxy/PNearPlane.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::NearPlaneUI)

namespace yq::tachyon {
    void NearPlaneUI::init_info()
    {
        auto w = writer<NearPlaneUI>();
        w.description("UIEditor for NearPlane");
        w.edits<PNearPlane>();
        w.field("Near Plane", &NearPlaneUI::near);
    }
    
    NearPlaneUI::NearPlaneUI(UIFlags flags)
    {
    }
    
    NearPlaneUI::NearPlaneUI(const NearPlaneUI& cp) : UIEditor(cp)
    {
    }
    
    NearPlaneUI* NearPlaneUI::clone() const
    {
        return new NearPlaneUI(*this);
    }

    void    NearPlaneUI::near()
    {
        PNearPlane* p   = snap()->proxy<PNearPlane>();
        if(!p)
            return ;
            
        double    v   = p->near_plane();
        if(ImGui::InputDouble("##near", v))
            p -> near_plane(SET, v);
    }
}
