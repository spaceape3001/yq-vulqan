////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AppEvent.hpp"

#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AppEvent)

namespace yq::tachyon {
    AppEventInfo::AppEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl) :
        EventInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    AppEvent::AppEvent(const Param& p) : Event(p)
    {
    }
    
    AppEvent::~AppEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void AppEvent::init_info()
    {
        auto w = writer<AppEvent>();
        w.description("Application event base class");
    }
}
