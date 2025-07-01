////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QAppLL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/AppEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

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
