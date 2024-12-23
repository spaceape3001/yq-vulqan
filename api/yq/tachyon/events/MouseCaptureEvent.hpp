////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>

namespace yq::tachyon {

    /*! \brief Emitted when mouse is set to "capture" mode
    */
    class MouseCaptureEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(MouseCaptureEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        MouseCaptureEvent(Window*, const Param& p = {});
        virtual ~MouseCaptureEvent();
        
        static void init_info();
    };
}
