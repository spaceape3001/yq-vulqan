////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/ViewerEvent.hpp>

namespace yq::tachyon {
    class ViewerResumeEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(ViewerResumeEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        ViewerResumeEvent(Viewer*, const Param& p = {});
        virtual ~ViewerResumeEvent();
        
        static void init_info();
    };
}
