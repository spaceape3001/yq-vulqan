////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RangeZDUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PRangeZD.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeᶻDUI)

namespace yq::tachyon {
    void RangeᶻDUI::init_meta()
    {
        auto w = writer<RangeᶻDUI>();
        w.description("UIEditor for RangeᶻD");
        w.edits<PRangeᶻD>();
        w.field("Z Range", &RangeᶻDUI::range);
    }
    
    RangeᶻDUI::RangeᶻDUI(UIFlags flags)
    {
    }
    
    RangeᶻDUI::RangeᶻDUI(const RangeᶻDUI& cp) : UIEditor(cp)
    {
    }
    
    RangeᶻDUI* RangeᶻDUI::clone() const
    {
        return new RangeᶻDUI(*this);
    }

    void    RangeᶻDUI::range()
    {
        PRangeᶻD* p   = snap()->proxy<PRangeᶻD>();
        if(!p)
            return ;
            
        RangeD    v   = p->z_range();
        if(im::input("##z_range", v))
            p -> z_range(SET, v);
    }
}
