////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>

namespace yq::tachyon {
    class WindowHideEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowHideEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowHideEvent(Viewer*, const Param& p = {});
        virtual ~WindowHideEvent();
        
        static void init_info();
    };
}
