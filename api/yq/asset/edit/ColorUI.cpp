////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ColorUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PColor.hpp>
#include <yq/tachyon/im/color.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ColorUI)

namespace yq::tachyon {
    void ColorUI::init_meta()
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
        if(im::color("##color", v))
            p -> color(SET, v);
    }
}
