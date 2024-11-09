////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>

namespace yq::tachyon {
    class WindowShowEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowShowEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowShowEvent(Viewer*, const Param& p = {});
        virtual ~WindowShowEvent();
        
        static void init_info();
    };
}
