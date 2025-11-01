////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/MouseEvent.hpp>

namespace yq::tachyon {
    class MouseMoveEvent : public MouseEvent {
        YQ_OBJECT_DECLARE(MouseMoveEvent, MouseEvent)
    public:
    
        MouseMoveEvent(const Header&, ModifierKeys, const Vector2D&, MouseButtons);

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_meta();

    protected:
        MouseMoveEvent(const MouseMoveEvent&, const Header&);
        virtual ~MouseMoveEvent();
        
    private:
        MouseMoveEvent(const MouseMoveEvent&) = delete;
        MouseMoveEvent(MouseMoveEvent&&) = delete;
        MouseMoveEvent& operator=(const MouseMoveEvent&) = delete;
        MouseMoveEvent& operator=(MouseMoveEvent&&) = delete;
    };
}

