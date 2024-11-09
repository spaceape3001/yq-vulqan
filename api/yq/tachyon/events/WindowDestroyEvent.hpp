////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>

namespace yq::tachyon {
    class WindowDestroyEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowDestroyEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowDestroyEvent(Viewer*, const Param& p = {});
        virtual ~WindowDestroyEvent();
        
        static void init_info();
    };
}
