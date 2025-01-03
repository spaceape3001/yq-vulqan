////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/WindowEvent.hpp>

namespace yq::tachyon {
    class WindowIconifyEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowIconifyEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowIconifyEvent(Window*, const Param& p = {});
        virtual ~WindowIconifyEvent();
        
        static void init_info();
    };
}
