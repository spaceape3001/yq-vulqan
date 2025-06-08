////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position3UI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/ui/UIEditorInfoWriter.hpp>
#include <tachyon/proxy/PPosition3.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position³UI)

namespace yq::tachyon {
    void Position³UI::init_info()
    {
        auto w = writer<Position³UI>();
        w.description("UIEditor for Position³");
        w.edits<PPosition³>();
        w.field("Position", &Position³UI::position);
    }
    
    Position³UI::Position³UI(UIFlags flags)
    {
    }
    
    Position³UI::Position³UI(const Position³UI& cp) : UIEditor(cp)
    {
    }
    
    Position³UI* Position³UI::clone() const
    {
        return new Position³UI(*this);
    }

    void    Position³UI::position()
    {
        PPosition³* p   = snap()->proxy<PPosition³>();
        if(!p)
            return ;
            
        Vector3D    v   = p->position();
        if(ImGui::InputDouble3("##position", &v))
            p -> position(SET, v);
    }
}
