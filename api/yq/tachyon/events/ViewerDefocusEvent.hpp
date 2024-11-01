////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/ViewerEvent.hpp>

namespace yq::tachyon {
    class ViewerDefocusEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(ViewerDefocusEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        ViewerDefocusEvent(Viewer*, const Param& p = {});
        virtual ~ViewerDefocusEvent();
        
        static void init_info();
    };
}
