////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/ViewerEvent.hpp>

namespace yq::tachyon {
    class ViewerMaximizeEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(ViewerMaximizeEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        ViewerMaximizeEvent(Viewer*, const Param& p = {});
        virtual ~ViewerMaximizeEvent();
        
        static void init_info();
    };
}
