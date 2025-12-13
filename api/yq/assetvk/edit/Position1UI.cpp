////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position1UI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition1.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position¹UI)

namespace yq::tachyon {
    void Position¹UI::init_meta()
    {
        auto w = writer<Position¹UI>();
        w.description("UIEditor for Position¹");
        w.edits<PPosition¹>();
        w.field("Position", &Position¹UI::position);
    }
    
    Position¹UI::Position¹UI(UIFlags flags)
    {
    }
    
    Position¹UI::Position¹UI(const Position¹UI& cp) : UIEditor(cp)
    {
    }
    
    Position¹UI* Position¹UI::clone() const
    {
        return new Position¹UI(*this);
    }

    void    Position¹UI::position()
    {
        PPosition¹* p   = snap()->proxy<PPosition¹>();
        if(!p)
            return ;
            
        Vector1D    v   = p->position();
        if(ImGui::Input("##position", v))
            p -> position(SET, v);
    }
}
