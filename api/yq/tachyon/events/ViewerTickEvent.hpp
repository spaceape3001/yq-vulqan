////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/ViewerEvent.hpp>

namespace yq::tachyon {
    class ViewerTickEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(ViewerTickEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        ViewerTickEvent(Viewer*, /* frame will go here */  const Param& p = {});
        virtual ~ViewerTickEvent();
        
        static void init_info();
    };
}
