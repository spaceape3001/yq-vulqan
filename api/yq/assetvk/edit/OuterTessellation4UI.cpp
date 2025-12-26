////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "OuterTessellation4UI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/POuterTessellation4.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::OuterTessellation⁴UI)

namespace yq::tachyon {
    void OuterTessellation⁴UI::init_meta()
    {
        auto w = writer<OuterTessellation⁴UI>();
        w.description("UIEditor for Outer Tessellation⁴");
        w.edits<POuterTessellation⁴>();
        w.field("Outer Tessellation", &OuterTessellation⁴UI::outer_tessellation);
    }
    
    OuterTessellation⁴UI::OuterTessellation⁴UI(UIFlags flags)
    {
    }
    
    OuterTessellation⁴UI::OuterTessellation⁴UI(const OuterTessellation⁴UI& cp) : UIEditor(cp)
    {
    }
    
    OuterTessellation⁴UI* OuterTessellation⁴UI::clone() const
    {
        return new OuterTessellation⁴UI(*this);
    }

    void    OuterTessellation⁴UI::outer_tessellation()
    {
        POuterTessellation⁴* p   = snap()->proxy<POuterTessellation⁴>();
        if(!p)
            return ;
            
        Vector4D    v   = p->outer_tessellation();
        ImGui::SetNextItemWidth(-1);
        if(ImGui::Input("##outer_tessellation", v))
            p -> outer_tessellation(SET, v);
    }
}
