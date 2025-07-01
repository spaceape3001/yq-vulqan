////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/gamepad/GamepadZeroEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {
    void GamepadZeroEvent::init_meta()
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
