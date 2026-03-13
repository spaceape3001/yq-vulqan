////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Scale2DUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PScale2D.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Scale²DUI)

namespace yq::tachyon {
    void Scale²DUI::init_meta()
    {
        auto w = writer<Scale²DUI>();
        w.description("UIEditor for Scale²");
        w.edits<PScale²D>();
        w.field("Scale", &Scale²DUI::scale);
    }
    
    Scale²DUI::Scale²DUI(UIFlags flags)
    {
    }
    
    Scale²DUI::Scale²DUI(const Scale²DUI& cp) : UIEditor(cp)
    {
    }
    
    Scale²DUI* Scale²DUI::clone() const
    {
        return new Scale²DUI(*this);
    }

    void    Scale²DUI::scale()
    {
        PScale²D* p   = snap()->proxy<PScale²D>();
        if(!p)
            return ;
            
        Vector2D    v   = p->scale();
        if(im::input("##scale", v))
            p -> scale(SET, v);
    }
}
