////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>

namespace yq::tachyon {
    class WindowRestoreEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowRestoreEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowRestoreEvent(Window*, const Param& p = {});
        virtual ~WindowRestoreEvent();
        
        static void init_info();
    };
}
