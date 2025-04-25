////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/gamepad/GamepadHatEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

namespace yq::tachyon {
    void GamepadHatEvent::init_info()
    {
        auto w = writer<GamepadHatEvent>();
        w.description("Gamepad Hat Event");
        w.property("hat", &GamepadHatEvent::m_hat).tag(kTag_Log).tag(kTag_Save);
        w.property("state", &GamepadHatEvent::m_state).tag(kTag_Log).tag(kTag_Save);
    }

    GamepadHatEvent::GamepadHatEvent(const Header&h, size_t _hat, HatState st) : 
        GamepadEvent(h), m_hat(_hat), m_state(st)
    {
    }
    
    GamepadHatEvent::GamepadHatEvent(const GamepadHatEvent& cp, const Header&h) : 
        GamepadEvent(cp, h), m_hat(cp.m_hat), m_state(cp.m_state)
    {
    }
    

    GamepadHatEvent::~GamepadHatEvent()
    {
    }

    PostCPtr    GamepadHatEvent::clone(rebind_k, const Header&h) const
    {
        return new GamepadHatEvent(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::GamepadHatEvent)
