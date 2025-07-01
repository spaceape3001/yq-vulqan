////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/window/FramebufferResizeEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::FramebufferResizeEvent)

namespace yq::tachyon {

    FramebufferResizeEvent::FramebufferResizeEvent(const Header&h, const Size2I& sz) : WindowEvent(h), m_size(sz)
    {
    }
    
    FramebufferResizeEvent::FramebufferResizeEvent(const FramebufferResizeEvent& cp, const Header&h) : 
        WindowEvent(cp, h), m_size(cp.m_size)
    {
    }

    FramebufferResizeEvent::~FramebufferResizeEvent()
    {
    }

    PostCPtr    FramebufferResizeEvent::clone(rebind_k, const Header&h) const 
    {
        return new FramebufferResizeEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void FramebufferResizeEvent::init_info()
    {
        auto w = writer<FramebufferResizeEvent>();
        w.description("Window Framebuffer Resize Event");
        w.property("w", &FramebufferResizeEvent::width).description("Window Window's new width").tag(kTag_Log);
        w.property("h", &FramebufferResizeEvent::height).description("Window Window's new height").tag(kTag_Log);
        w.property("size", &FramebufferResizeEvent::m_size).description("Window Window's new size").tag(kTag_Save);
    }
}
