////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Scale4DUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PScale4D.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Scale⁴DUI)

namespace yq::tachyon {
    void Scale⁴DUI::init_meta()
    {
        auto w = writer<Scale⁴DUI>();
        w.description("UIEditor for Scale⁴");
        w.edits<PScale⁴D>();
        w.field("Scale", &Scale⁴DUI::scale);
    }
    
    Scale⁴DUI::Scale⁴DUI(UIFlags flags)
    {
    }
    
    Scale⁴DUI::Scale⁴DUI(const Scale⁴DUI& cp) : UIEditor(cp)
    {
    }
    
    Scale⁴DUI* Scale⁴DUI::clone() const
    {
        return new Scale⁴DUI(*this);
    }

    void    Scale⁴DUI::scale()
    {
        PScale⁴D* p   = snap()->proxy<PScale⁴D>();
        if(!p)
            return ;
            
        Vector4D    v   = p->scale();
        if(im::input("##scale", v))
            p -> scale(SET, v);
    }
}
