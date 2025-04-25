////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/WindowEvent.hpp>

#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowEvent)

namespace yq::tachyon {
    WindowEvent::WindowEvent(const Header&h) : Event(h)
    {
    }
    
    WindowEvent::WindowEvent(const WindowEvent& cp, const Header& h) : Event(cp, h)
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
