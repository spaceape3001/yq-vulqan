////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RangeWUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PRangeW.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeʷUI)

namespace yq::tachyon {
    void RangeʷUI::init_meta()
    {
        auto w = writer<RangeʷUI>();
        w.description("UIEditor for Rangeʷ");
        w.edits<PRangeʷ>();
        w.field("W Range", &RangeʷUI::range);
    }
    
    RangeʷUI::RangeʷUI(UIFlags flags)
    {
    }
    
    RangeʷUI::RangeʷUI(const RangeʷUI& cp) : UIEditor(cp)
    {
    }
    
    RangeʷUI* RangeʷUI::clone() const
    {
        return new RangeʷUI(*this);
    }

    void    RangeʷUI::range()
    {
        PRangeʷ* p   = snap()->proxy<PRangeʷ>();
        if(!p)
            return ;
            
        RangeD    v   = p->w_range();
        if(im::input("##w_range", v))
            p -> w_range(SET, v);
    }
}
