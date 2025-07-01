////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position4UI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/ui/UIEditorMetaWriter.hpp>
#include <tachyon/proxy/PPosition4.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position⁴UI)

namespace yq::tachyon {
    void Position⁴UI::init_meta()
    {
        auto w = writer<Position⁴UI>();
        w.description("UIEditor for Position⁴");
        w.edits<PPosition⁴>();
        w.field("Position", &Position⁴UI::position);
    }
    
    Position⁴UI::Position⁴UI(UIFlags flags)
    {
    }
    
    Position⁴UI::Position⁴UI(const Position⁴UI& cp) : UIEditor(cp)
    {
    }
    
    Position⁴UI* Position⁴UI::clone() const
    {
        return new Position⁴UI(*this);
    }

    void    Position⁴UI::position()
    {
        PPosition⁴* p   = snap()->proxy<PPosition⁴>();
        if(!p)
            return ;
            
        Vector4D    v   = p->position();
        if(ImGui::Input("##position", v))
            p -> position(SET, v);
    }
}
