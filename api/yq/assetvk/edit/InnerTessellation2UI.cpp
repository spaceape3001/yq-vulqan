////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "InnerTessellation2UI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PInnerTessellation2.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::InnerTessellation²UI)

namespace yq::tachyon {
    void InnerTessellation²UI::init_meta()
    {
        auto w = writer<InnerTessellation²UI>();
        w.description("UIEditor for Inner Tessellation²");
        w.edits<PInnerTessellation²>();
        w.field("Inner Tessellation", &InnerTessellation²UI::inner_tessellation);
    }
    
    InnerTessellation²UI::InnerTessellation²UI(UIFlags flags)
    {
    }
    
    InnerTessellation²UI::InnerTessellation²UI(const InnerTessellation²UI& cp) : UIEditor(cp)
    {
    }
    
    InnerTessellation²UI* InnerTessellation²UI::clone() const
    {
        return new InnerTessellation²UI(*this);
    }

    void    InnerTessellation²UI::inner_tessellation()
    {
        PInnerTessellation²* p   = snap()->proxy<PInnerTessellation²>();
        if(!p)
            return ;
            
        Vector2D    v   = p->inner_tessellation();
        ImGui::SetNextItemWidth(-1);
        if(ImGui::Input("##inner_tessellation", v))
            p -> inner_tessellation(SET, v);
    }
}
