////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>

namespace yq::tachyon {
    class CursorNormalEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(CursorNormalEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        CursorNormalEvent(Viewer*, const Param& p = {});
        virtual ~CursorNormalEvent();
        
        static void init_info();
    };
}
