////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RangeWDUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PRangeWD.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeʷDUI)

namespace yq::tachyon {
    void RangeʷDUI::init_meta()
    {
        auto w = writer<RangeʷDUI>();
        w.description("UIEditor for RangeʷD");
        w.edits<PRangeʷD>();
        w.field("W Range", &RangeʷDUI::range);
    }
    
    RangeʷDUI::RangeʷDUI(UIFlags flags)
    {
    }
    
    RangeʷDUI::RangeʷDUI(const RangeʷDUI& cp) : UIEditor(cp)
    {
    }
    
    RangeʷDUI* RangeʷDUI::clone() const
    {
        return new RangeʷDUI(*this);
    }

    void    RangeʷDUI::range()
    {
        PRangeʷD* p   = snap()->proxy<PRangeʷD>();
        if(!p)
            return ;
            
        RangeD    v   = p->w_range();
        if(im::input("##w_range", v))
            p -> w_range(SET, v);
    }
}
