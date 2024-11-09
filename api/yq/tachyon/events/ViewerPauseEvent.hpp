////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/ViewerEvent.hpp>

namespace yq::tachyon {
    class ViewerPauseEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(ViewerPauseEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        ViewerPauseEvent(Viewer*, const Param& p = {});
        virtual ~ViewerPauseEvent();
        
        static void init_info();
    };
}
