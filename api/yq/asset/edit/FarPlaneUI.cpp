////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "FarPlaneUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PFarPlane.hpp>

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
        if(im::input("##far", v))
            p -> far_plane(SET, v);
    }
}
