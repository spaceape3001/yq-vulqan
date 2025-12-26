////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Count1UI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PCount1.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Count¹UI)

namespace yq::tachyon {
    void Count¹UI::init_meta()
    {
        auto w = writer<Count¹UI>();
        w.description("UIEditor for Count¹");
        w.edits<PCount¹>();
        w.field("Count", &Count¹UI::count);
    }
    
    Count¹UI::Count¹UI(UIFlags flags)
    {
    }
    
    Count¹UI::Count¹UI(const Count¹UI& cp) : UIEditor(cp)
    {
    }
    
    Count¹UI* Count¹UI::clone() const
    {
        return new Count¹UI(*this);
    }

    void    Count¹UI::count()
    {
        PCount¹* p   = snap()->proxy<PCount¹>();
        if(!p)
            return ;
            
        Vector1U    v   = p->count();
        ImGui::SetNextItemWidth(-1);
        if(ImGui::Input("##count", v))
            p -> count(SET, v);
    }
}
