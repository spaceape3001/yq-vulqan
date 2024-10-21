////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/MouseEvent.hpp>

namespace yq::tachyon {
    class MouseRelease : public MouseEvent {
        YQ_OBJECT_DECLARE(MouseRelease, MouseEvent)
    public:
    
        struct Param : public MouseEvent::Param {
            MouseButton     button      = {};
        };
    
        MouseRelease(const Param&);

        MouseButton         button() const { return m_button; }
        virtual ~MouseRelease();
        
        bool    left() const;
        bool    right() const;
        bool    middle() const;
        
    private:
        MouseButton     m_button;
    };
}
