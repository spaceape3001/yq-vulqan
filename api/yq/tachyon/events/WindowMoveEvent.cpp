////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowMoveEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowMoveEvent)

namespace yq::tachyon {

    WindowMoveEvent::WindowMoveEvent(Window* v, const Vector2I& pos, const Param& p) : WindowEvent(v, p), m_position(pos)
    {
    }
    
    WindowMoveEvent::~WindowMoveEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowMoveEvent::init_info()
    {
        auto w = writer<WindowMoveEvent>();
        w.description("Window Move Event");
        w.property("x", &WindowMoveEvent::x).description("Window Window's new x-position").tag(kTag_Log);
        w.property("y", &WindowMoveEvent::y).description("Window Window's new y-position").tag(kTag_Log);
        w.property("position", &WindowMoveEvent::position).description("Window Window's new position");
    }
}
