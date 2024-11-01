////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/ViewerEvent.hpp>

namespace yq::tachyon {
    class ViewerRestoreEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(ViewerRestoreEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        ViewerRestoreEvent(Viewer*, const Param& p = {});
        virtual ~ViewerRestoreEvent();
        
        static void init_info();
    };
}
