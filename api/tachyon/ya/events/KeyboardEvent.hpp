////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/InputEvent.hpp>

namespace yq::tachyon {
    class Window;
    class Viewer;


    class KeyboardEvent : public InputEvent {
        YQ_OBJECT_DECLARE(KeyboardEvent, InputEvent)
    public:
    
        static void init_info();

    protected:
        KeyboardEvent(const Header&, ModifierKeys);
        KeyboardEvent(const KeyboardEvent&, const Header&);
        virtual ~KeyboardEvent();
        
    private:
        KeyboardEvent(const KeyboardEvent&) = delete;
        KeyboardEvent(KeyboardEvent&&) = delete;
        KeyboardEvent& operator=(const KeyboardEvent&) = delete;
        KeyboardEvent& operator=(KeyboardEvent&&) = delete;
    };
}
