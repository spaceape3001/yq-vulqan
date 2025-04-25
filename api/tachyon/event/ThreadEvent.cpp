////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/ThreadEvent.hpp>

#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ThreadEvent)

namespace yq::tachyon {
    ThreadEvent::ThreadEvent(const Header&h) : Event(h)
    {
    }
    
    ThreadEvent::ThreadEvent(const ThreadEvent& cp, const Header&h) : Event(cp, h)
    {
    }

    ThreadEvent::~ThreadEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ThreadEvent::init_info()
    {
        auto w = writer<ThreadEvent>();
        w.description("Thread event base class");
    }
}
