////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Scale2UI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PScale2.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Scale²UI)

namespace yq::tachyon {
    void Scale²UI::init_meta()
    {
        auto w = writer<Scale²UI>();
        w.description("UIEditor for Scale²");
        w.edits<PScale²>();
        w.field("Scale", &Scale²UI::scale);
    }
    
    Scale²UI::Scale²UI(UIFlags flags)
    {
    }
    
    Scale²UI::Scale²UI(const Scale²UI& cp) : UIEditor(cp)
    {
    }
    
    Scale²UI* Scale²UI::clone() const
    {
        return new Scale²UI(*this);
    }

    void    Scale²UI::scale()
    {
        PScale²* p   = snap()->proxy<PScale²>();
        if(!p)
            return ;
            
        Vector2D    v   = p->scale();
        if(ImGui::Input("##scale", v))
            p -> scale(SET, v);
    }
}
