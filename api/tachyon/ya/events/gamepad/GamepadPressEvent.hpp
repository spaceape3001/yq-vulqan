////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/GamepadEvent.hpp>

namespace yq::tachyon {
    class GamepadPressEvent : public GamepadEvent {
        YQ_OBJECT_DECLARE(GamepadPressEvent, GamepadEvent);
    public:
        static void init_info();
    
        GamepadPressEvent(const Header&, size_t);

        size_t  button() const { return m_button; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        GamepadPressEvent(const GamepadPressEvent&, const Header&);
        ~GamepadPressEvent();
    private:
        size_t  m_button;
        
        GamepadPressEvent(const GamepadPressEvent&) = delete;
        GamepadPressEvent(GamepadPressEvent&&) = delete;
        GamepadPressEvent& operator=(const GamepadPressEvent&) = delete;
        GamepadPressEvent& operator=(GamepadPressEvent&&) = delete;
    };
}
