////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/ViewerEvent.hpp>

namespace yq::tachyon {
    class ViewerFocusEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(ViewerFocusEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        ViewerFocusEvent(Viewer*, const Param& p = {});
        virtual ~ViewerFocusEvent();
        
        static void init_info();
    };
}
