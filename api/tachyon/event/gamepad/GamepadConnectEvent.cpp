////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/gamepad/GamepadConnectEvent.hpp>
#include <tachyon/api/EventInfoWriter.hpp>

namespace yq::tachyon {
    void GamepadConnectEvent::init_info()
    {
        auto w = writer<GamepadConnectEvent>();
        w.description("Gamepad Connection Event");
    }

    GamepadConnectEvent::GamepadConnectEvent(const Header&h) : GamepadEvent(h)
    {
    }
    
    GamepadConnectEvent::GamepadConnectEvent(const GamepadConnectEvent& cp, const Header&h) : GamepadEvent(cp, h)
    {
    }

    GamepadConnectEvent::~GamepadConnectEvent()
    {
    }

    PostCPtr    GamepadConnectEvent::clone(rebind_k, const Header&h) const
    {
        return new GamepadConnectEvent(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::GamepadConnectEvent)
