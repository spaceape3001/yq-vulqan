////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Count1UUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_uint32.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PCount1U.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Count¹UUI)

namespace yq::tachyon {
    void Count¹UUI::init_meta()
    {
        auto w = writer<Count¹UUI>();
        w.description("UIEditor for Count¹");
        w.edits<PCount¹U>();
        w.field("Count", &Count¹UUI::count);
    }
    
    Count¹UUI::Count¹UUI(UIFlags flags)
    {
    }
    
    Count¹UUI::Count¹UUI(const Count¹UUI& cp) : UIEditor(cp)
    {
    }
    
    Count¹UUI* Count¹UUI::clone() const
    {
        return new Count¹UUI(*this);
    }

    void    Count¹UUI::count()
    {
        PCount¹U* p   = snap()->proxy<PCount¹U>();
        if(!p)
            return ;
            
        Vector1U    v   = p->count();
        if(im::input("##count", v))
            p -> count(SET, v);
    }
}
