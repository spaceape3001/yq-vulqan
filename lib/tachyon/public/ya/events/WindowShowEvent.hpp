////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/WindowEvent.hpp>

namespace yq::tachyon {
    class WindowShowEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowShowEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowShowEvent(Window*, const Param& p = {});
        virtual ~WindowShowEvent();
        
        static void init_info();
    };
}
