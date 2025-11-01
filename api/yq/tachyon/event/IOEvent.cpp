////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QIOLL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/IOEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

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
    
    void IOEvent::init_meta()
    {
        auto w = writer<IOEvent>();
        w.abstract();
        w.description("IO Event");
    }
}
