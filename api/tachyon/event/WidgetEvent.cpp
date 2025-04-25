////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/WidgetEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WidgetEvent)

namespace yq::tachyon {
    WidgetEvent::WidgetEvent(const Header&h) : Event(h)
    {
    }
    
    WidgetEvent::WidgetEvent(const WidgetEvent&cp, const Header&h) : Event(cp, h)
    {
    }
    
    WidgetEvent::~WidgetEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WidgetEvent::init_info()
    {
        auto w = writer<WidgetEvent>();
        w.description("WidgetEvent base class");
    }
}
