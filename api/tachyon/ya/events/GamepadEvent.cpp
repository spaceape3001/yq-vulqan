////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/GamepadEvent.hpp>

#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::GamepadEvent)

namespace yq::tachyon {
    GamepadEvent::GamepadEvent(const Header& h) : Event(h)
    {
    }
    
    GamepadEvent::GamepadEvent(const GamepadEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    GamepadEvent::~GamepadEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void GamepadEvent::init_info()
    {
        auto w = writer<GamepadEvent>();
        w.description("Gamepad event base class");
    }
}
