////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Scale4UI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PScale4.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Scale⁴UI)

namespace yq::tachyon {
    void Scale⁴UI::init_meta()
    {
        auto w = writer<Scale⁴UI>();
        w.description("UIEditor for Scale⁴");
        w.edits<PScale⁴>();
        w.field("Scale", &Scale⁴UI::scale);
    }
    
    Scale⁴UI::Scale⁴UI(UIFlags flags)
    {
    }
    
    Scale⁴UI::Scale⁴UI(const Scale⁴UI& cp) : UIEditor(cp)
    {
    }
    
    Scale⁴UI* Scale⁴UI::clone() const
    {
        return new Scale⁴UI(*this);
    }

    void    Scale⁴UI::scale()
    {
        PScale⁴* p   = snap()->proxy<PScale⁴>();
        if(!p)
            return ;
            
        Vector4D    v   = p->scale();
        if(im::input("##scale", v))
            p -> scale(SET, v);
    }
}
