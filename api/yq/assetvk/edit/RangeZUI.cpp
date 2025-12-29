////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RangeZUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PRangeZ.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeᶻUI)

namespace yq::tachyon {
    void RangeᶻUI::init_meta()
    {
        auto w = writer<RangeᶻUI>();
        w.description("UIEditor for Rangeᶻ");
        w.edits<PRangeᶻ>();
        w.field("Z Range", &RangeᶻUI::range);
    }
    
    RangeᶻUI::RangeᶻUI(UIFlags flags)
    {
    }
    
    RangeᶻUI::RangeᶻUI(const RangeᶻUI& cp) : UIEditor(cp)
    {
    }
    
    RangeᶻUI* RangeᶻUI::clone() const
    {
        return new RangeᶻUI(*this);
    }

    void    RangeᶻUI::range()
    {
        PRangeᶻ* p   = snap()->proxy<PRangeᶻ>();
        if(!p)
            return ;
            
        RangeD    v   = p->z_range();
        if(im::input("##z_range", v))
            p -> z_range(SET, v);
    }
}
