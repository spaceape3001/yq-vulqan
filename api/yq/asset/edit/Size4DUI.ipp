////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size4DUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PSize4D.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size⁴DUI)

namespace yq::tachyon {
    void Size⁴DUI::init_meta()
    {
        auto w = writer<Size⁴DUI>();
        w.description("UIEditor for Size⁴");
        w.edits<PSize⁴D>();
        w.field("Size", &Size⁴DUI::size);
    }
    
    Size⁴DUI::Size⁴DUI(UIFlags flags)
    {
    }
    
    Size⁴DUI::Size⁴DUI(const Size⁴DUI& cp) : UIEditor(cp)
    {
    }
    
    Size⁴DUI* Size⁴DUI::clone() const
    {
        return new Size⁴DUI(*this);
    }

    void    Size⁴DUI::size()
    {
        PSize⁴D* p   = snap()->proxy<PSize⁴D>();
        if(!p)
            return ;
            
        Size4D    v   = p->size();
        if(im::input("##size", v))
            p -> size(SET, v);
    }
}
