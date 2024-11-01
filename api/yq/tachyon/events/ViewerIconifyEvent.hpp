////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/ViewerEvent.hpp>

namespace yq::tachyon {
    class ViewerIconifyEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(ViewerIconifyEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        ViewerIconifyEvent(Viewer*, const Param& p = {});
        virtual ~ViewerIconifyEvent();
        
        static void init_info();
    };
}
