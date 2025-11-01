////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/GamepadEvent.hpp>

namespace yq::tachyon {
    class GamepadDisconnectEvent : public GamepadEvent {
        YQ_OBJECT_DECLARE(GamepadDisconnectEvent, GamepadEvent);
    public:
        static void init_meta();
        
        GamepadDisconnectEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        GamepadDisconnectEvent(const GamepadDisconnectEvent&, const Header&);
        ~GamepadDisconnectEvent();
        
    private:
        GamepadDisconnectEvent(const GamepadDisconnectEvent&) = delete;
        GamepadDisconnectEvent(GamepadDisconnectEvent&&) = delete;
        GamepadDisconnectEvent& operator=(const GamepadDisconnectEvent&) = delete;
        GamepadDisconnectEvent& operator=(GamepadDisconnectEvent&&) = delete;
    };
}
