////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size2UI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PSize2.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size²UI)

namespace yq::tachyon {
    void Size²UI::init_meta()
    {
        auto w = writer<Size²UI>();
        w.description("UIEditor for Size²");
        w.edits<PSize²>();
        w.field("Size", &Size²UI::size);
    }
    
    Size²UI::Size²UI(UIFlags flags)
    {
    }
    
    Size²UI::Size²UI(const Size²UI& cp) : UIEditor(cp)
    {
    }
    
    Size²UI* Size²UI::clone() const
    {
        return new Size²UI(*this);
    }

    void    Size²UI::size()
    {
        PSize²* p   = snap()->proxy<PSize²>();
        if(!p)
            return ;
            
        Size2D    v   = p->size();
        if(ImGui::Input("##size", v))
            p -> size(SET, v);
    }
}
