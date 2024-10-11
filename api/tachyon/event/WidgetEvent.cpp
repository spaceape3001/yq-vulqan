////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WidgetEvent.hpp"

#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WidgetEvent)

namespace yq::tachyon {
    
    WidgetEventInfo::WidgetEventInfo(std::string_view zName, const EventInfo& base, const std::source_location& sl) :
        EventInfo(zName, base, sl)
    {
        set(Flag::WIDGET);
    }

    ////////////////////////////////////////////////////////////////////////////

    WidgetEvent::WidgetEvent()
    {
    }
    
    WidgetEvent::~WidgetEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_widget_event()
    {
        {
            auto w = writer<WidgetEvent>();
            w.description("WidgetEvent base class");
        }
    }
    
    YQ_INVOKE(reg_widget_event();)
}
