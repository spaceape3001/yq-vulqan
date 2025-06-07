////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ColorTriangle3UI.hpp"
#include <tachyon/rendered/ColorTriangle3.hpp>
#include <tachyon/ui/UIEditorInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ColorTriangle³UI)

namespace yq::tachyon {
    void ColorTriangle³UI::init_info()
    {
        auto w = writer<ColorTriangle³UI>();
        w.description("UIEditor for ColorTriangle³");
        w.edits<ColorTriangle³>();
    }
    
    ColorTriangle³UI::ColorTriangle³UI(UIFlags flags)
    {
    }
    
    ColorTriangle³UI::ColorTriangle³UI(const ColorTriangle³UI& cp) : UIEditor(cp)
    {
    }
    
    ColorTriangle³UI* ColorTriangle³UI::clone() const
    {
        return new ColorTriangle³UI(*this);
    }
    
}
