////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/ViewerEvent.hpp>

namespace yq::tachyon {

    /*! \brief Emitted when mouse is set to "capture" mode
    */
    class MouseCaptureEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(MouseCaptureEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        MouseCaptureEvent(Viewer*, const Param& p = {});
        virtual ~MouseCaptureEvent();
        
        static void init_info();
    };
}
