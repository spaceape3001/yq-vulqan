////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>

namespace yq::tachyon {
    class WindowFocusEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowFocusEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowFocusEvent(Viewer*, const Param& p = {});
        virtual ~WindowFocusEvent();
        
        static void init_info();
    };
}
