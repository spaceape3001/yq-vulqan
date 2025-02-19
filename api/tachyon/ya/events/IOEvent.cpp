////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QIOLL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/IOEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::IOEvent)

namespace yq::tachyon {
    IOEvent::IOEvent(const Header& h) : Event(h)
    {
    }
    
    IOEvent::IOEvent(const IOEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    IOEvent::~IOEvent()
    {
    }
    
    void IOEvent::init_info()
    {
        auto w = writer<IOEvent>();
        w.abstract();
        w.description("IO Event");
    }
}
