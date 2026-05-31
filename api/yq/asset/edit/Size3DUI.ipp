////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size3DUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PSize3D.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size³DUI)

namespace yq::tachyon {
    void Size³DUI::init_meta()
    {
        auto w = writer<Size³DUI>();
        w.description("UIEditor for Size³");
        w.edits<PSize³D>();
        w.field("Size", &Size³DUI::size);
    }
    
    Size³DUI::Size³DUI(UIFlags flags)
    {
    }
    
    Size³DUI::Size³DUI(const Size³DUI& cp) : UIEditor(cp)
    {
    }
    
    Size³DUI* Size³DUI::clone() const
    {
        return new Size³DUI(*this);
    }

    void    Size³DUI::size()
    {
        PSize³D* p   = snap()->proxy<PSize³D>();
        if(!p)
            return ;
            
        Size3D    v   = p->size();
        if(im::input("##size", v))
            p -> size(SET, v);
    }
}
