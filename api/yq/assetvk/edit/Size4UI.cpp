////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size4UI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PSize4.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size⁴UI)

namespace yq::tachyon {
    void Size⁴UI::init_meta()
    {
        auto w = writer<Size⁴UI>();
        w.description("UIEditor for Size⁴");
        w.edits<PSize⁴>();
        w.field("Size", &Size⁴UI::size);
    }
    
    Size⁴UI::Size⁴UI(UIFlags flags)
    {
    }
    
    Size⁴UI::Size⁴UI(const Size⁴UI& cp) : UIEditor(cp)
    {
    }
    
    Size⁴UI* Size⁴UI::clone() const
    {
        return new Size⁴UI(*this);
    }

    void    Size⁴UI::size()
    {
        PSize⁴* p   = snap()->proxy<PSize⁴>();
        if(!p)
            return ;
            
        Size4D    v   = p->size();
        ImGui::SetNextItemWidth(-1);
        if(ImGui::Input("##size", v))
            p -> size(SET, v);
    }
}
