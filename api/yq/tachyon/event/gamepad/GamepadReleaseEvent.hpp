////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/GamepadEvent.hpp>

namespace yq::tachyon {
    class GamepadReleaseEvent : public GamepadEvent {
        YQ_OBJECT_DECLARE(GamepadReleaseEvent, GamepadEvent);
    public:
        static void init_meta();
    
        GamepadReleaseEvent(const Header&, size_t);
        ~GamepadReleaseEvent();
        
        size_t  button() const { return m_button; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        GamepadReleaseEvent(const GamepadReleaseEvent&, const Header&);
    
    private:
        size_t  m_button;
        
        GamepadReleaseEvent(const GamepadReleaseEvent&) = delete;
        GamepadReleaseEvent(GamepadReleaseEvent&&) = delete;
        GamepadReleaseEvent& operator=(const GamepadReleaseEvent&) = delete;
        GamepadReleaseEvent& operator=(GamepadReleaseEvent&&) = delete;
    };
}
