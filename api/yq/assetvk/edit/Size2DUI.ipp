////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size2DUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PSize2D.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size²DUI)

namespace yq::tachyon {
    void Size²DUI::init_meta()
    {
        auto w = writer<Size²DUI>();
        w.description("UIEditor for Size²");
        w.edits<PSize²D>();
        w.field("Size", &Size²DUI::size);
    }
    
    Size²DUI::Size²DUI(UIFlags flags)
    {
    }
    
    Size²DUI::Size²DUI(const Size²DUI& cp) : UIEditor(cp)
    {
    }
    
    Size²DUI* Size²DUI::clone() const
    {
        return new Size²DUI(*this);
    }

    void    Size²DUI::size()
    {
        PSize²D* p   = snap()->proxy<PSize²D>();
        if(!p)
            return ;
            
        Size2D    v   = p->size();
        if(im::input("##size", v))
            p -> size(SET, v);
    }
}
