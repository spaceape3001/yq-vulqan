////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Count4UI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PCount4.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Count⁴UI)

namespace yq::tachyon {
    void Count⁴UI::init_meta()
    {
        auto w = writer<Count⁴UI>();
        w.description("UIEditor for Count⁴");
        w.edits<PCount⁴>();
        w.field("Count", &Count⁴UI::count);
    }
    
    Count⁴UI::Count⁴UI(UIFlags flags)
    {
    }
    
    Count⁴UI::Count⁴UI(const Count⁴UI& cp) : UIEditor(cp)
    {
    }
    
    Count⁴UI* Count⁴UI::clone() const
    {
        return new Count⁴UI(*this);
    }

    void    Count⁴UI::count()
    {
        PCount⁴* p   = snap()->proxy<PCount⁴>();
        if(!p)
            return ;
            
        Vector4U    v   = p->count();
        if(ImGui::Input("##count", v))
            p -> count(SET, v);
    }
}
