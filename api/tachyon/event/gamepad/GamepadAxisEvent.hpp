////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/GamepadEvent.hpp>

namespace yq::tachyon {
    class GamepadAxisEvent : public GamepadEvent {
        YQ_OBJECT_DECLARE(GamepadAxisEvent, GamepadEvent);
    public:
        static void init_meta();
    
        GamepadAxisEvent(const Header&, size_t axis, float value, float delta);
        
        size_t  axis() const { return m_axis; }
        float   value() const { return m_value; }
        float   delta() const { return m_delta; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        GamepadAxisEvent(const GamepadAxisEvent&, const Header&);
        ~GamepadAxisEvent();
        
    private:
        size_t      m_axis;
        float       m_value;
        float       m_delta;
        
        GamepadAxisEvent(const GamepadAxisEvent&) = delete;
        GamepadAxisEvent(GamepadAxisEvent&&) = delete;
        GamepadAxisEvent& operator=(const GamepadAxisEvent&) = delete;
        GamepadAxisEvent& operator=(GamepadAxisEvent&&) = delete;
    };
}
