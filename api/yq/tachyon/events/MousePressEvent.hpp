////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/MouseEvent.hpp>

namespace yq::tachyon {
    class MousePressEvent : public MouseEvent {
        YQ_OBJECT_DECLARE(MousePressEvent, MouseEvent)
    public:
    
        struct Param : public MouseEvent::Param {
            MouseButton     button;
        };
    
        MousePressEvent(Window*, const Param&);
        MousePressEvent(WindowID, const Param&);
        
        //! Scan code from the operating system (no interpretation)
        MouseButton         button() const { return m_button; }
        
        bool    left() const;
        bool    right() const;
        bool    middle() const;

        virtual ~MousePressEvent();
        
        static void init_info();
        
    private:
    
        const MouseButton m_button;
    };
}
