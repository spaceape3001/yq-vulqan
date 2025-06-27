////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size3UI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/ui/UIEditorInfoWriter.hpp>
#include <tachyon/proxy/PSize3.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size³UI)

namespace yq::tachyon {
    void Size³UI::init_info()
    {
        auto w = writer<Size³UI>();
        w.description("UIEditor for Size³");
        w.edits<PSize³>();
        w.field("Size", &Size³UI::size);
    }
    
    Size³UI::Size³UI(UIFlags flags)
    {
    }
    
    Size³UI::Size³UI(const Size³UI& cp) : UIEditor(cp)
    {
    }
    
    Size³UI* Size³UI::clone() const
    {
        return new Size³UI(*this);
    }

    void    Size³UI::size()
    {
        PSize³* p   = snap()->proxy<PSize³>();
        if(!p)
            return ;
            
        Size3D    v   = p->size();
        if(ImGui::Input("##size", v))
            p -> size(SET, v);
    }
}
