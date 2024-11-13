////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowScaleEvent.hpp"
#include <yq/tachyon/post/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowScaleEvent)

namespace yq::tachyon {

    WindowScaleEvent::WindowScaleEvent(Viewer* v, const Vector2F& sc, const Param& p) : WindowEvent(v, p), m_scale(sc)
    {
    }
    
    WindowScaleEvent::~WindowScaleEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowScaleEvent::init_info()
    {
        auto w = writer<WindowScaleEvent>();
        w.description("Window Scale Event");
        w.property("x", &WindowScaleEvent::x).description("Window Window's new x-scale").tag(kTag_Log);
        w.property("y", &WindowScaleEvent::y).description("Window Window's new y-scale").tag(kTag_Log);
        w.property("scale", &WindowScaleEvent::scale).description("Window Window's new scale");
    }
}
