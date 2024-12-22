////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>

namespace yq::tachyon {
    class CursorDisableEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(CursorDisableEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        CursorDisableEvent(Window*, const Param& p = {});
        virtual ~CursorDisableEvent();
        
        static void init_info();
    };
}
