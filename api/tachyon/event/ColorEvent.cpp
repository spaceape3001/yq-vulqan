////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QColorLL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/ColorEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ColorEvent)

namespace yq::tachyon {
    ColorEvent::ColorEvent(const Header& h) : Event(h)
    {
    }
    
    ColorEvent::ColorEvent(const ColorEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    ColorEvent::~ColorEvent()
    {
    }
    
    void ColorEvent::init_info()
    {
        auto w = writer<ColorEvent>();
        w.abstract();
        w.description("Color Event");
    }
}
