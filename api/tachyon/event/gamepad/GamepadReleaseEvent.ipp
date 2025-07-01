////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/gamepad/GamepadReleaseEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {
    void GamepadReleaseEvent::init_info()
    {
        auto w = writer<GamepadReleaseEvent>();
        w.description("Gamepad Release Event");
        w.property("button", &GamepadReleaseEvent::m_button).tag(kTag_Log).tag(kTag_Save);
    }

    GamepadReleaseEvent::GamepadReleaseEvent(const Header& h, size_t btn) : 
        GamepadEvent(h), m_button(btn)
    {
    }
    
    GamepadReleaseEvent::GamepadReleaseEvent(const GamepadReleaseEvent& cp, const Header& h) : 
        GamepadEvent(cp, h), m_button(cp.m_button)
    {
    }

    GamepadReleaseEvent::~GamepadReleaseEvent()
    {
    }

    PostCPtr    GamepadReleaseEvent::clone(rebind_k, const Header&h) const 
    {
        return new GamepadReleaseEvent(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::GamepadReleaseEvent)
