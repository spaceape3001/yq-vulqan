////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/GamepadEvent.hpp>

#include <tachyon/api/EventMetaWriter.hpp>

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

    void GamepadEvent::init_meta()
    {
        auto w = writer<GamepadEvent>();
        w.description("Gamepad event base class");
    }
}
