////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/ViewerEvent.hpp>

namespace yq::tachyon {
    class MouseHideEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(MouseHideEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        MouseHideEvent(Viewer*, const Param& p = {});
        virtual ~MouseHideEvent();
        
        static void init_info();
    };
}
