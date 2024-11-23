////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowFrameBufferResizeEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowFrameBufferResizeEvent)

namespace yq::tachyon {

    WindowFrameBufferResizeEvent::WindowFrameBufferResizeEvent(Viewer* v, const Size2I& sz, const Param& p) : WindowEvent(v, p), m_size(sz)
    {
    }
    
    WindowFrameBufferResizeEvent::~WindowFrameBufferResizeEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowFrameBufferResizeEvent::init_info()
    {
        auto w = writer<WindowFrameBufferResizeEvent>();
        w.description("Window Framebuffer Resize Event");
        w.property("width", &WindowFrameBufferResizeEvent::width).description("Window Window's new width").tag(kTag_Log);
        w.property("height", &WindowFrameBufferResizeEvent::height).description("Window Window's new height").tag(kTag_Log);
        w.property("size", &WindowFrameBufferResizeEvent::size).description("Window Window's new size");
    }
}
