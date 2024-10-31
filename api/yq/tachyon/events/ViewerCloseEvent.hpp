////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/ViewerEvent.hpp>

namespace yq::tachyon {
    class ViewerCloseEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(ViewerCloseEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        ViewerCloseEvent(Viewer*, const Param& p = {});
        virtual ~ViewerCloseEvent();
    };
}
