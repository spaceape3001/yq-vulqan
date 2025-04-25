////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/GamepadEvent.hpp>

namespace yq::tachyon {
    class GamepadConnectEvent : public GamepadEvent {
        YQ_OBJECT_DECLARE(GamepadConnectEvent, GamepadEvent);
    public:
        static void init_info();
    
        GamepadConnectEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        GamepadConnectEvent(const GamepadConnectEvent&, const Header&);
        ~GamepadConnectEvent();
        
    private:
        GamepadConnectEvent(const GamepadConnectEvent&) = delete;
        GamepadConnectEvent(GamepadConnectEvent&&) = delete;
        GamepadConnectEvent& operator=(const GamepadConnectEvent&) = delete;
        GamepadConnectEvent& operator=(GamepadConnectEvent&&) = delete;
    };
}
