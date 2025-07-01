////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ColorUI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/ui/UIEditorMetaWriter.hpp>
#include <tachyon/proxy/PColor.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ColorUI)

namespace yq::tachyon {
    void ColorUI::init_info()
    {
        auto w = writer<ColorUI>();
        w.description("UIEditor for Color");
        w.edits<PColor>();
        w.field("Primary Color", &ColorUI::color);
    }
    
    ColorUI::ColorUI(UIFlags flags)
    {
    }
    
    ColorUI::ColorUI(const ColorUI& cp) : UIEditor(cp)
    {
    }
    
    ColorUI* ColorUI::clone() const
    {
        return new ColorUI(*this);
    }

    void    ColorUI::color()
    {
        PColor* p   = snap()->proxy<PColor>();
        if(!p)
            return ;
            
        RGBA4F    v   = p->color();
        if(ImGui::ColorEdit("##color", v))
            p -> color(SET, v);
    }
}
