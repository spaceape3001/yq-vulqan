////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Scale3DUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PScale3D.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Scale³DUI)

namespace yq::tachyon {
    void Scale³DUI::init_meta()
    {
        auto w = writer<Scale³DUI>();
        w.description("UIEditor for Scale³");
        w.edits<PScale³D>();
        w.field("Scale", &Scale³DUI::scale);
    }
    
    Scale³DUI::Scale³DUI(UIFlags flags)
    {
    }
    
    Scale³DUI::Scale³DUI(const Scale³DUI& cp) : UIEditor(cp)
    {
    }
    
    Scale³DUI* Scale³DUI::clone() const
    {
        return new Scale³DUI(*this);
    }

    void    Scale³DUI::scale()
    {
        PScale³D* p   = snap()->proxy<PScale³D>();
        if(!p)
            return ;
            
        Vector3D    v   = p->scale();
        if(im::input("##scale", v))
            p -> scale(SET, v);
    }
}
