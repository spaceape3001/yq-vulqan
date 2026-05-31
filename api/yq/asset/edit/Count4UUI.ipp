////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Count4UUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_uint32.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PCount4U.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Count⁴UUI)

namespace yq::tachyon {
    void Count⁴UUI::init_meta()
    {
        auto w = writer<Count⁴UUI>();
        w.description("UIEditor for Count⁴");
        w.edits<PCount⁴U>();
        w.field("Count", &Count⁴UUI::count);
    }
    
    Count⁴UUI::Count⁴UUI(UIFlags flags)
    {
    }
    
    Count⁴UUI::Count⁴UUI(const Count⁴UUI& cp) : UIEditor(cp)
    {
    }
    
    Count⁴UUI* Count⁴UUI::clone() const
    {
        return new Count⁴UUI(*this);
    }

    void    Count⁴UUI::count()
    {
        PCount⁴U* p   = snap()->proxy<PCount⁴U>();
        if(!p)
            return ;
            
        Vector4U    v   = p->count();
        if(im::input("##count", v))
            p -> count(SET, v);
    }
}
