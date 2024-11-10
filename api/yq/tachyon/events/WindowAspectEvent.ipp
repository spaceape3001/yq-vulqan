////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowAspectEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowAspectEvent)

namespace yq::tachyon {

    WindowAspectEvent::WindowAspectEvent(Viewer* v, const Size2I& asp, const Param& p) : WindowEvent(v, p), m_aspect(asp)
    {
    }
    
    WindowAspectEvent::~WindowAspectEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowAspectEvent::init_info()
    {
        auto w = writer<WindowAspectEvent>();
        w.description("Window Aspect Event");
        w.property("aspect", &WindowAspectEvent::aspect).description("Aspect ratio");
        w.property("width", &WindowAspectEvent::width).description("Aspect width").alias("w");
        w.property("height", &WindowAspectEvent::height).description("Aspect height").alias("h");
    }
}
