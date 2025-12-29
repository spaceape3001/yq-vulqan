////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "NearPlaneUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PNearPlane.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::NearPlaneUI)

namespace yq::tachyon {
    void NearPlaneUI::init_meta()
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
        if(im::input("##near", v))
            p -> near_plane(SET, v);
    }
}
