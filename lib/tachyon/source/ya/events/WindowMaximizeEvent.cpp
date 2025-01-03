////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/WindowMaximizeEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowMaximizeEvent)

namespace yq::tachyon {

    WindowMaximizeEvent::WindowMaximizeEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    WindowMaximizeEvent::~WindowMaximizeEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowMaximizeEvent::init_info()
    {
        auto w = writer<WindowMaximizeEvent>();
        w.description("Window Maximize Event");
    }
}
