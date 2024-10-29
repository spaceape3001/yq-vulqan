////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/input/MouseEvent.hpp>

namespace yq::tachyon {
    class MousePress : public MouseEvent {
        YQ_OBJECT_DECLARE(MousePress, MouseEvent)
    public:
    
        struct Param : public MouseEvent::Param {
            MouseButton     button      = {};
        };
    
        MousePress(const Param&);

        MouseButton         button() const { return m_button; }
        virtual ~MousePress();
        
        bool    left() const;
        bool    right() const;
        bool    middle() const;
        
    private:
        MouseButton     m_button;
    };
}
