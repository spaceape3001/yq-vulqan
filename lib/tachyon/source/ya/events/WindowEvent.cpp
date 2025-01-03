////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/WindowEvent.hpp>

#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowEvent)

namespace yq::tachyon {
    WindowEventInfo::WindowEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl) :
        EventInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    WindowEvent::WindowEvent(WindowID v, const Param& p) : Event(p), WindowBind(v)
    {
    }
    
    WindowEvent::WindowEvent(const Window* v, const Param& p) : Event(p), WindowBind(v)
    {
    }
    
    WindowEvent::~WindowEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowEvent::init_info()
    {
        auto w = writer<WindowEvent>();
        w.description("Window event base class");
    }
}
