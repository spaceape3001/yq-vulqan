////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AppEvent.hpp"

#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AppEvent)

namespace yq::tachyon {
    AppEventInfo::AppEventInfo(std::string_view zName, post::EventInfo& base, const std::source_location& sl) :
        post::EventInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    AppEvent::AppEvent(const Param& p) : post::Event(p)
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
    
    YQ_INVOKE(AppEvent::init_info();)
}
