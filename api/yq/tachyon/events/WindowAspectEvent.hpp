////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class Window;
    
    class WindowAspectEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowAspectEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowAspectEvent(Window*, const Size2I&, const Param& p = {});
        virtual ~WindowAspectEvent();
        
        static void init_info();

        const Size2I& aspect() const { return m_aspect; }
        int width() const { return m_aspect.x; }
        int height() const { return m_aspect.y; }
        
    private:
        const Size2I    m_aspect;
    };
}
