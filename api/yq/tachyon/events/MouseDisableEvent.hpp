////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/ViewerEvent.hpp>

namespace yq::tachyon {
    class MouseDisableEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(MouseDisableEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        MouseDisableEvent(Viewer*, const Param& p = {});
        virtual ~MouseDisableEvent();
        
        static void init_info();
    };
}
