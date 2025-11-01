////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>
#include <yq/tachyon/os/Gamepad.hpp>

namespace yq::tachyon {
    class GamepadEvent : public Event {
        YQ_OBJECT_DECLARE(GamepadEvent, Event)
    public:

        static void init_meta();

    protected:
        GamepadEvent(const Header&);
        GamepadEvent(const GamepadEvent&, const Header&);
        virtual ~GamepadEvent();
        
    private:
        GamepadEvent(const GamepadEvent&) = delete;
        GamepadEvent(GamepadEvent&&) = delete;
        GamepadEvent& operator=(const GamepadEvent&) = delete;
        GamepadEvent& operator=(GamepadEvent&&) = delete;
    };
}
