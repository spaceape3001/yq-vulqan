////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/color/ColorChangeEvent.hpp>
#include <tachyon/api/EventInfoWriter.hpp>
#include <tachyon/tags.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ColorChangeEvent)

namespace yq::tachyon {

    ColorChangeEvent::ColorChangeEvent(const Header&h, const RGBA4F& clr) : ColorEvent(h), m_color(clr)
    {
    }

    ColorChangeEvent::ColorChangeEvent(const ColorChangeEvent& cp, const Header& h) : 
        ColorEvent(cp, h), m_color(cp.m_color)
    {
    }
    
    ColorChangeEvent::~ColorChangeEvent()
    {
    }

    PostCPtr    ColorChangeEvent::clone(rebind_k, const Header&h) const 
    {
        return new ColorChangeEvent(*this, h);
    }

    void        ColorChangeEvent::set_color(const RGBA4F& v)
    {
        m_color = v;
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ColorChangeEvent::init_info()
    {
        auto w = writer<ColorChangeEvent>();
        w.description("Color Change Event");
        w.property("color", &ColorChangeEvent::m_color).tag({kTag_Log});
    }
}
