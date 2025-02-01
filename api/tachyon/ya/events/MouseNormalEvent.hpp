////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/WindowEvent.hpp>

namespace yq::tachyon {
    
    /*! \brief Emitted when mouse returns to normal mode
    */
    class MouseNormalEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(MouseNormalEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        MouseNormalEvent(Window*, const Param& p = {});
        virtual ~MouseNormalEvent();
        
        static void init_info();
    };
}
