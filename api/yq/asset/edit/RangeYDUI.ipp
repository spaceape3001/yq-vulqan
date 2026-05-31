////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RangeYDUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PRangeYD.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeʸDUI)

namespace yq::tachyon {
    void RangeʸDUI::init_meta()
    {
        auto w = writer<RangeʸDUI>();
        w.description("UIEditor for RangeʸD");
        w.edits<PRangeʸD>();
        w.field("Y Range", &RangeʸDUI::range);
    }
    
    RangeʸDUI::RangeʸDUI(UIFlags flags)
    {
    }
    
    RangeʸDUI::RangeʸDUI(const RangeʸDUI& cp) : UIEditor(cp)
    {
    }
    
    RangeʸDUI* RangeʸDUI::clone() const
    {
        return new RangeʸDUI(*this);
    }

    void    RangeʸDUI::range()
    {
        PRangeʸD* p   = snap()->proxy<PRangeʸD>();
        if(!p)
            return ;
            
        RangeD    v   = p->y_range();
        if(im::input("##y_range", v))
            p -> y_range(SET, v);
    }
}
