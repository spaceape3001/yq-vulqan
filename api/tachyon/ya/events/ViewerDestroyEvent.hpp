////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/ViewerEvent.hpp>

namespace yq::tachyon {
    class ViewerDestroyEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(ViewerDestroyEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        ViewerDestroyEvent(Viewer*, const Param& p = {});
        virtual ~ViewerDestroyEvent();
        
        static void init_info();
    };
}
