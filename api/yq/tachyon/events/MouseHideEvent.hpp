////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>

namespace yq::tachyon {
    
    /*! \brief Emitted when mouse returns to normal mode
    */
    class MouseHideEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(MouseHideEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        MouseHideEvent(Window*, const Param& p = {});
        virtual ~MouseHideEvent();
        
        static void init_info();
    };
}
