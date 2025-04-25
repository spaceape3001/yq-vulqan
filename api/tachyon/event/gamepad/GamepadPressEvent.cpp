////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/gamepad/GamepadPressEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

namespace yq::tachyon {
    void GamepadPressEvent::init_info()
    {
        auto w = writer<GamepadPressEvent>();
        w.description("Gamepad Press Event");
        w.property("button", &GamepadPressEvent::m_button).tag(kTag_Log).tag(kTag_Save);
    }

    GamepadPressEvent::GamepadPressEvent(const Header&h, size_t btn) : GamepadEvent(h), m_button(btn)
    {
    }
    
    GamepadPressEvent::GamepadPressEvent(const GamepadPressEvent& cp, const Header&h) : 
        GamepadEvent(cp, h), m_button(cp.m_button)
    {
    }

    GamepadPressEvent::~GamepadPressEvent()
    {
    }

    PostCPtr    GamepadPressEvent::clone(rebind_k, const Header&h) const
    {
        return new GamepadPressEvent(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::GamepadPressEvent)
