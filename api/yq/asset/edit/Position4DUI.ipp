////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position4DUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition4D.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position⁴DUI)

namespace yq::tachyon {
    void Position⁴DUI::init_meta()
    {
        auto w = writer<Position⁴DUI>();
        w.description("UIEditor for Position⁴");
        w.edits<PPosition⁴D>();
        w.field("Position", &Position⁴DUI::position);
    }
    
    Position⁴DUI::Position⁴DUI(UIFlags flags)
    {
    }
    
    Position⁴DUI::Position⁴DUI(const Position⁴DUI& cp) : UIEditor(cp)
    {
    }
    
    Position⁴DUI* Position⁴DUI::clone() const
    {
        return new Position⁴DUI(*this);
    }

    void    Position⁴DUI::position()
    {
        PPosition⁴D* p   = snap()->proxy<PPosition⁴D>();
        if(!p)
            return ;
            
        Vector4D    v   = p->position();
        if(im::input("##position", v))
            p -> position(SET, v);
    }
}
