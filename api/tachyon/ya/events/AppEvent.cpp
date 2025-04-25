////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QAppLL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/AppEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AppEvent)

namespace yq::tachyon {
    AppEvent::AppEvent(const Header& h) : Event(h)
    {
    }
    
    AppEvent::AppEvent(const AppEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    AppEvent::~AppEvent()
    {
    }
    
    void AppEvent::init_info()
    {
        auto w = writer<AppEvent>();
        w.abstract();
        w.description("App Event");
    }
}
