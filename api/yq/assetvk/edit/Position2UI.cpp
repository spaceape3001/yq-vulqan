////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position2UI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition2.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position²UI)

namespace yq::tachyon {
    void Position²UI::init_meta()
    {
        auto w = writer<Position²UI>();
        w.description("UIEditor for Position²");
        w.edits<PPosition²>();
        w.field("Position", &Position²UI::position);
    }
    
    Position²UI::Position²UI(UIFlags flags)
    {
    }
    
    Position²UI::Position²UI(const Position²UI& cp) : UIEditor(cp)
    {
    }
    
    Position²UI* Position²UI::clone() const
    {
        return new Position²UI(*this);
    }

    void    Position²UI::position()
    {
        PPosition²* p   = snap()->proxy<PPosition²>();
        if(!p)
            return ;
            
        Vector2D    v   = p->position();
        if(im::input("##position", v))
            p -> position(SET, v);
    }
}
