////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/MouseEvent.hpp>

namespace yq::tachyon {
    class MouseLeaveEvent : public MouseEvent {
        YQ_OBJECT_DECLARE(MouseLeaveEvent, MouseEvent)
    public:
    
        MouseLeaveEvent(const Header&, ModifierKeys, const Vector2D&, MouseButtons);

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_meta();

    protected:
        MouseLeaveEvent(const MouseLeaveEvent&, const Header&);
        virtual ~MouseLeaveEvent();
        
    private:
        MouseLeaveEvent(const MouseLeaveEvent&) = delete;
        MouseLeaveEvent(MouseLeaveEvent&&) = delete;
        MouseLeaveEvent& operator=(const MouseLeaveEvent&) = delete;
        MouseLeaveEvent& operator=(MouseLeaveEvent&&) = delete;
    };
}

