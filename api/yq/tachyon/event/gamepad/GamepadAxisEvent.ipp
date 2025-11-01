////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/gamepad/GamepadAxisEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {
    void GamepadAxisEvent::init_meta()
    {
        auto w = writer<GamepadAxisEvent>();
        w.description("Gamepad Axis Event");
        w.property("axis", &GamepadAxisEvent::m_axis).description("Axis of motion").tag(kTag_Log).tag(kTag_Save);
        w.property("value", &GamepadAxisEvent::m_value).description("Current axis value").tag(kTag_Log).tag(kTag_Save);
        w.property("delta", &GamepadAxisEvent::m_delta).description("Change in value").tag(kTag_Log).tag(kTag_Save);
    }

    GamepadAxisEvent::GamepadAxisEvent(const Header&h, size_t _axis, float _value, float _delta) : 
        GamepadEvent(h), m_axis(_axis), m_value(_value), m_delta(_delta)
    {
    }
    
    GamepadAxisEvent::GamepadAxisEvent(const GamepadAxisEvent& cp, const Header&h) : 
        GamepadEvent(cp, h), m_axis(cp.m_axis), m_value(cp.m_value), m_delta(cp.m_delta)
    {
    }

    GamepadAxisEvent::~GamepadAxisEvent()
    {
    }

    PostCPtr    GamepadAxisEvent::clone(rebind_k, const Header&h) const 
    {
        return new GamepadAxisEvent(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::GamepadAxisEvent)
