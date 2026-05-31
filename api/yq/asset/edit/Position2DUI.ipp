////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position2DUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition2D.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position²DUI)

namespace yq::tachyon {
    void Position²DUI::init_meta()
    {
        auto w = writer<Position²DUI>();
        w.description("UIEditor for Position²");
        w.edits<PPosition²D>();
        w.field("Position", &Position²DUI::position);
    }
    
    Position²DUI::Position²DUI(UIFlags flags)
    {
    }
    
    Position²DUI::Position²DUI(const Position²DUI& cp) : UIEditor(cp)
    {
    }
    
    Position²DUI* Position²DUI::clone() const
    {
        return new Position²DUI(*this);
    }

    void    Position²DUI::position()
    {
        PPosition²D* p   = snap()->proxy<PPosition²D>();
        if(!p)
            return ;
            
        Vector2D    v   = p->position();
        if(im::input("##position", v))
            p -> position(SET, v);
    }
}
