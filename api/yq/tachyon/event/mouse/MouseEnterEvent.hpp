////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/MouseEvent.hpp>

namespace yq::tachyon {
    class MouseEnterEvent : public MouseEvent {
        YQ_OBJECT_DECLARE(MouseEnterEvent, MouseEvent)
    public:
    
        MouseEnterEvent(const Header&, ModifierKeys, const Vector2D&, MouseButtons);

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_meta();

    protected:
        MouseEnterEvent(const MouseEnterEvent&, const Header&);
        virtual ~MouseEnterEvent();
        
    private:
        MouseEnterEvent(const MouseEnterEvent&) = delete;
        MouseEnterEvent(MouseEnterEvent&&) = delete;
        MouseEnterEvent& operator=(const MouseEnterEvent&) = delete;
        MouseEnterEvent& operator=(MouseEnterEvent&&) = delete;
    };
}

