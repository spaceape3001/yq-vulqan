////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RangeXUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PRangeX.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeˣUI)

namespace yq::tachyon {
    void RangeˣUI::init_meta()
    {
        auto w = writer<RangeˣUI>();
        w.description("UIEditor for Rangeˣ");
        w.edits<PRangeˣ>();
        w.field("X Range", &RangeˣUI::range);
    }
    
    RangeˣUI::RangeˣUI(UIFlags flags)
    {
    }
    
    RangeˣUI::RangeˣUI(const RangeˣUI& cp) : UIEditor(cp)
    {
    }
    
    RangeˣUI* RangeˣUI::clone() const
    {
        return new RangeˣUI(*this);
    }

    void    RangeˣUI::range()
    {
        PRangeˣ* p   = snap()->proxy<PRangeˣ>();
        if(!p)
            return ;
            
        RangeD    v   = p->x_range();
        ImGui::SetNextItemWidth(-1);
        if(ImGui::Input("##x_range", v))
            p -> x_range(SET, v);
    }
}
