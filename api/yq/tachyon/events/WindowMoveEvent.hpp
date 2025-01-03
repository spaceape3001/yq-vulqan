////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    class WindowMoveEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowMoveEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowMoveEvent(Window*, const Vector2I&, const Param& p = {});
        virtual ~WindowMoveEvent();
        
        static void init_info();
        
        const Vector2I& position() const { return m_position; }
        int x() const { return m_position.x; }
        int y() const { return m_position.y; }
        
    private:
        const Vector2I    m_position;
    };
}
