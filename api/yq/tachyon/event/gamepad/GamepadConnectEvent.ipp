////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/gamepad/GamepadConnectEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {
    void GamepadConnectEvent::init_meta()
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
