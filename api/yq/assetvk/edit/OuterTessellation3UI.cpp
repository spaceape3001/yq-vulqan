////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "OuterTessellation3UI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/POuterTessellation3.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::OuterTessellation³UI)

namespace yq::tachyon {
    void OuterTessellation³UI::init_meta()
    {
        auto w = writer<OuterTessellation³UI>();
        w.description("UIEditor for Outer Tessellation³");
        w.edits<POuterTessellation³>();
        w.field("Outer Tessellation", &OuterTessellation³UI::outer_tessellation);
    }
    
    OuterTessellation³UI::OuterTessellation³UI(UIFlags flags)
    {
    }
    
    OuterTessellation³UI::OuterTessellation³UI(const OuterTessellation³UI& cp) : UIEditor(cp)
    {
    }
    
    OuterTessellation³UI* OuterTessellation³UI::clone() const
    {
        return new OuterTessellation³UI(*this);
    }

    void    OuterTessellation³UI::outer_tessellation()
    {
        POuterTessellation³* p   = snap()->proxy<POuterTessellation³>();
        if(!p)
            return ;
            
        Vector3D    v   = p->outer_tessellation();
        ImGui::SetNextItemWidth(-1);
        if(ImGui::Input("##outer_tessellation", v))
            p -> outer_tessellation(SET, v);
    }
}
