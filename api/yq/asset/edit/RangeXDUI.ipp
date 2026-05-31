////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RangeXDUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PRangeXD.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeˣDUI)

namespace yq::tachyon {
    void RangeˣDUI::init_meta()
    {
        auto w = writer<RangeˣDUI>();
        w.description("UIEditor for RangeˣD");
        w.edits<PRangeˣD>();
        w.field("X Range", &RangeˣDUI::range);
    }
    
    RangeˣDUI::RangeˣDUI(UIFlags flags)
    {
    }
    
    RangeˣDUI::RangeˣDUI(const RangeˣDUI& cp) : UIEditor(cp)
    {
    }
    
    RangeˣDUI* RangeˣDUI::clone() const
    {
        return new RangeˣDUI(*this);
    }

    void    RangeˣDUI::range()
    {
        PRangeˣD* p   = snap()->proxy<PRangeˣD>();
        if(!p)
            return ;
            
        RangeD    v   = p->x_range();
        if(im::input("##x_range", v))
            p -> x_range(SET, v);
    }
}
