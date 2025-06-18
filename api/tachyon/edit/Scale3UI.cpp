////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Scale3UI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/ui/UIEditorInfoWriter.hpp>
#include <tachyon/proxy/PScale3.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Scale³UI)

namespace yq::tachyon {
    void Scale³UI::init_info()
    {
        auto w = writer<Scale³UI>();
        w.description("UIEditor for Scale³");
        w.edits<PScale³>();
        w.field("Scale", &Scale³UI::scale);
    }
    
    Scale³UI::Scale³UI(UIFlags flags)
    {
    }
    
    Scale³UI::Scale³UI(const Scale³UI& cp) : UIEditor(cp)
    {
    }
    
    Scale³UI* Scale³UI::clone() const
    {
        return new Scale³UI(*this);
    }

    void    Scale³UI::scale()
    {
        PScale³* p   = snap()->proxy<PScale³>();
        if(!p)
            return ;
            
        Vector3D    v   = p->scale();
        if(ImGui::Input("##scale", v))
            p -> scale(SET, v);
    }
}
