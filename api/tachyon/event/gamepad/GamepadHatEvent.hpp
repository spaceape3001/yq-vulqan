////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/GamepadEvent.hpp>
#include <tachyon/os/HatState.hpp>

namespace yq::tachyon {
    class GamepadHatEvent : public GamepadEvent {
        YQ_OBJECT_DECLARE(GamepadHatEvent, GamepadEvent);
    public:
        static void init_info();
    
        HatState    state() const { return m_state; }
        size_t      hat() const { return m_hat; }
    
        GamepadHatEvent(const Header&, size_t, HatState);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        ~GamepadHatEvent();
        GamepadHatEvent(const GamepadHatEvent&, const Header&);

    private:
        size_t    m_hat;
        HatState  m_state;
        
        GamepadHatEvent(const GamepadHatEvent&) = delete;
        GamepadHatEvent(GamepadHatEvent&&) = delete;
        GamepadHatEvent& operator=(const GamepadHatEvent&) = delete;
        GamepadHatEvent& operator=(GamepadHatEvent&&) = delete;
    };
}
