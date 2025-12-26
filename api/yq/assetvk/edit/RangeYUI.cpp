////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RangeYUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PRangeY.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeʸUI)

namespace yq::tachyon {
    void RangeʸUI::init_meta()
    {
        auto w = writer<RangeʸUI>();
        w.description("UIEditor for Rangeʸ");
        w.edits<PRangeʸ>();
        w.field("Y Range", &RangeʸUI::range);
    }
    
    RangeʸUI::RangeʸUI(UIFlags flags)
    {
    }
    
    RangeʸUI::RangeʸUI(const RangeʸUI& cp) : UIEditor(cp)
    {
    }
    
    RangeʸUI* RangeʸUI::clone() const
    {
        return new RangeʸUI(*this);
    }

    void    RangeʸUI::range()
    {
        PRangeʸ* p   = snap()->proxy<PRangeʸ>();
        if(!p)
            return ;
            
        RangeD    v   = p->y_range();
        ImGui::SetNextItemWidth(-1);
        if(ImGui::Input("##y_range", v))
            p -> y_range(SET, v);
    }
}
