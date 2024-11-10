////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>

namespace yq::tachyon {
    class CursorHideEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(CursorHideEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        CursorHideEvent(Viewer*, const Param& p = {});
        virtual ~CursorHideEvent();
        
        static void init_info();
    };
}
