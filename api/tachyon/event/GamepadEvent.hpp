////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Event.hpp>
#include <tachyon/os/Gamepad.hpp>

namespace yq::tachyon {
    class GamepadEvent : public Event {
        YQ_OBJECT_DECLARE(GamepadEvent, Event)
    public:

        static void init_info();

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
