////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Count3UI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_uint32.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PCount3.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Count³UI)

namespace yq::tachyon {
    void Count³UI::init_meta()
    {
        auto w = writer<Count³UI>();
        w.description("UIEditor for Count³");
        w.edits<PCount³>();
        w.field("Count", &Count³UI::count);
    }
    
    Count³UI::Count³UI(UIFlags flags)
    {
    }
    
    Count³UI::Count³UI(const Count³UI& cp) : UIEditor(cp)
    {
    }
    
    Count³UI* Count³UI::clone() const
    {
        return new Count³UI(*this);
    }

    void    Count³UI::count()
    {
        PCount³* p   = snap()->proxy<PCount³>();
        if(!p)
            return ;
            
        Vector3U    v   = p->count();
        if(im::input("##count", v))
            p -> count(SET, v);
    }
}
