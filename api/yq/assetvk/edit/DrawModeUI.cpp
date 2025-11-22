////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "DrawModeUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PDrawMode.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::DrawModeUI)

namespace yq::tachyon {
    void DrawModeUI::init_meta()
    {
        auto w = writer<DrawModeUI>();
        w.description("UIEditor for Draw Mode");
        w.edits<PDrawMode>();
        w.field("Draw Mode", &DrawModeUI::draw_mode);
    }
    
    DrawModeUI::DrawModeUI(UIFlags flags)
    {
    }
    
    DrawModeUI::DrawModeUI(const DrawModeUI& cp) : UIEditor(cp)
    {
    }
    
    DrawModeUI* DrawModeUI::clone() const
    {
        return new DrawModeUI(*this);
    }

    void    DrawModeUI::draw_mode()
    {
        PDrawMode* p   = snap()->proxy<PDrawMode>();
        if(!p)
            return ;
            
        DrawMode    v   = p->draw_mode();
        if(ImGui::Combo("##draw_mode", v))
            p -> draw_mode(SET, v);
    }
}
