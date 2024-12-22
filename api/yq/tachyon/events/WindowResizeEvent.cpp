////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowResizeEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowResizeEvent)

namespace yq::tachyon {

    WindowResizeEvent::WindowResizeEvent(Window* v, const Size2I& sz, const Param& p) : WindowEvent(v, p), m_size(sz)
    {
    }
    
    WindowResizeEvent::~WindowResizeEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowResizeEvent::init_info()
    {
        auto w = writer<WindowResizeEvent>();
        w.description("Window Resize Event");
        w.property("width", &WindowResizeEvent::width).description("Window Window's new width").tag(kTag_Log);
        w.property("height", &WindowResizeEvent::height).description("Window Window's new height").tag(kTag_Log);
        w.property("size", &WindowResizeEvent::size).description("Window Window's new size");
    }
}
