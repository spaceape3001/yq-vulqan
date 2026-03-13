////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Count3UUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_uint32.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PCount3U.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Count³UUI)

namespace yq::tachyon {
    void Count³UUI::init_meta()
    {
        auto w = writer<Count³UUI>();
        w.description("UIEditor for Count³");
        w.edits<PCount³U>();
        w.field("Count", &Count³UUI::count);
    }
    
    Count³UUI::Count³UUI(UIFlags flags)
    {
    }
    
    Count³UUI::Count³UUI(const Count³UUI& cp) : UIEditor(cp)
    {
    }
    
    Count³UUI* Count³UUI::clone() const
    {
        return new Count³UUI(*this);
    }

    void    Count³UUI::count()
    {
        PCount³U* p   = snap()->proxy<PCount³U>();
        if(!p)
            return ;
            
        Vector3U    v   = p->count();
        if(im::input("##count", v))
            p -> count(SET, v);
    }
}
