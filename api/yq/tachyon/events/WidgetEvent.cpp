////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WidgetEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WidgetEvent)

namespace yq::tachyon {
    
    WidgetEventInfo::WidgetEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl) :
        EventInfo(zName, base, sl)
    {
        set(Flag::WIDGET);
    }

    ////////////////////////////////////////////////////////////////////////////

    WidgetEvent::WidgetEvent(Widget* w, const Param&p) : Event(p), m_widget(w)
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
