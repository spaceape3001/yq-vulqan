////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>

namespace yq::tachyon {
    class WindowMaximizeEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowMaximizeEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowMaximizeEvent(Window*, const Param& p = {});
        virtual ~WindowMaximizeEvent();
        
        static void init_info();
    };
}
