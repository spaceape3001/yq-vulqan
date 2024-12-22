////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class WindowFrameBufferResizeEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowFrameBufferResizeEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowFrameBufferResizeEvent(Window*, const Size2I&, const Param& p = {});
        virtual ~WindowFrameBufferResizeEvent();
        
        static void init_info();
        
        const Size2I& size() const { return m_size; }
        double width() const { return m_size.x; }
        double height() const { return m_size.y; }
        
    private:
        const Size2I    m_size;
    };
}
