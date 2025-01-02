////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ThreadEvent.hpp"

#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ThreadEvent)

namespace yq::tachyon {
    ThreadEventInfo::ThreadEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl) :
        EventInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    ThreadEvent::ThreadEvent(const Thread* v, const Param& p) : Event(p), ThreadBind(v)
    {
    }
    
    ThreadEvent::ThreadEvent(ThreadID v, const Param& p) : Event(p), ThreadBind(v)
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
