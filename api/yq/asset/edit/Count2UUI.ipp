////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Count2UUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_uint32.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PCount2U.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Count²UUI)

namespace yq::tachyon {
    void Count²UUI::init_meta()
    {
        auto w = writer<Count²UUI>();
        w.description("UIEditor for Count²");
        w.edits<PCount²U>();
        w.field("Count", &Count²UUI::count);
    }
    
    Count²UUI::Count²UUI(UIFlags flags)
    {
    }
    
    Count²UUI::Count²UUI(const Count²UUI& cp) : UIEditor(cp)
    {
    }
    
    Count²UUI* Count²UUI::clone() const
    {
        return new Count²UUI(*this);
    }

    void    Count²UUI::count()
    {
        PCount²U* p   = snap()->proxy<PCount²U>();
        if(!p)
            return ;
            
        Vector2U    v   = p->count();
        if(im::input("##count", v))
            p -> count(SET, v);
    }
}
