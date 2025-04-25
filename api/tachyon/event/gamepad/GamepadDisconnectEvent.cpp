////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/gamepad/GamepadDisconnectEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

namespace yq::tachyon {
    void GamepadDisconnectEvent::init_info()
    {
        auto w = writer<GamepadDisconnectEvent>();
        w.description("Gamepad Disconnection Event");
    }

    GamepadDisconnectEvent::GamepadDisconnectEvent(const Header&h) : GamepadEvent(h)
    {
    }
    
    GamepadDisconnectEvent::GamepadDisconnectEvent(const GamepadDisconnectEvent& cp, const Header&h) : GamepadEvent(cp, h)
    {
    }

    GamepadDisconnectEvent::~GamepadDisconnectEvent()
    {
    }

    PostCPtr    GamepadDisconnectEvent::clone(rebind_k, const Header& h) const 
    {
        return new GamepadDisconnectEvent(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::GamepadDisconnectEvent)
