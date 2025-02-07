////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/gamepad/GamepadZeroEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

namespace yq::tachyon {
    void GamepadZeroEvent::init_info()
    {
        auto w = writer<GamepadZeroEvent>();
        w.description("Gamepad Zeroion Event");
    }

    GamepadZeroEvent::GamepadZeroEvent(const Header&h) : GamepadEvent(h)
    {
    }
    
    GamepadZeroEvent::GamepadZeroEvent(const GamepadZeroEvent& cp, const Header&h) : GamepadEvent(cp, h)
    {
    }

    GamepadZeroEvent::~GamepadZeroEvent()
    {
    }

    PostCPtr    GamepadZeroEvent::clone(rebind_k, const Header&h) const
    {
        return new GamepadZeroEvent(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::GamepadZeroEvent)
