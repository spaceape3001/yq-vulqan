////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "FarPlaneUI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/ui/UIEditorMetaWriter.hpp>
#include <tachyon/proxy/PFarPlane.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::FarPlaneUI)

namespace yq::tachyon {
    void FarPlaneUI::init_meta()
    {
        auto w = writer<FarPlaneUI>();
        w.description("UIEditor for FarPlane");
        w.edits<PFarPlane>();
        w.field("Far Plane", &FarPlaneUI::far);
    }
    
    FarPlaneUI::FarPlaneUI(UIFlags flags)
    {
    }
    
    FarPlaneUI::FarPlaneUI(const FarPlaneUI& cp) : UIEditor(cp)
    {
    }
    
    FarPlaneUI* FarPlaneUI::clone() const
    {
        return new FarPlaneUI(*this);
    }

    void    FarPlaneUI::far()
    {
        PFarPlane* p   = snap()->proxy<PFarPlane>();
        if(!p)
            return ;
            
        double    v   = p->far_plane();
        if(ImGui::Input("##far", v))
            p -> far_plane(SET, v);
    }
}
