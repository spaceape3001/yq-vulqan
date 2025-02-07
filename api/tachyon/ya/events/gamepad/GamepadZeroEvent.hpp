////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/GamepadEvent.hpp>

namespace yq::tachyon {
    class GamepadZeroEvent : public GamepadEvent {
        YQ_OBJECT_DECLARE(GamepadZeroEvent, GamepadEvent);
    public:
        static void init_info();
    
        GamepadZeroEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        GamepadZeroEvent(const GamepadZeroEvent&, const Header&);
        ~GamepadZeroEvent();
        
    private:
        GamepadZeroEvent(const GamepadZeroEvent&) = delete;
        GamepadZeroEvent(GamepadZeroEvent&&) = delete;
        GamepadZeroEvent& operator=(const GamepadZeroEvent&) = delete;
        GamepadZeroEvent& operator=(GamepadZeroEvent&&) = delete;
    };
}
