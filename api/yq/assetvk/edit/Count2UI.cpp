////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Count2UI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_uint32.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PCount2.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Count²UI)

namespace yq::tachyon {
    void Count²UI::init_meta()
    {
        auto w = writer<Count²UI>();
        w.description("UIEditor for Count²");
        w.edits<PCount²>();
        w.field("Count", &Count²UI::count);
    }
    
    Count²UI::Count²UI(UIFlags flags)
    {
    }
    
    Count²UI::Count²UI(const Count²UI& cp) : UIEditor(cp)
    {
    }
    
    Count²UI* Count²UI::clone() const
    {
        return new Count²UI(*this);
    }

    void    Count²UI::count()
    {
        PCount²* p   = snap()->proxy<PCount²>();
        if(!p)
            return ;
            
        Vector2U    v   = p->count();
        if(im::input("##count", v))
            p -> count(SET, v);
    }
}
