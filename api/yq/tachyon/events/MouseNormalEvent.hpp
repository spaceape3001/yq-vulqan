////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/ViewerEvent.hpp>

namespace yq::tachyon {
    
    /*! \brief Emitted when mouse returns to normal mode
    */
    class MouseNormalEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(MouseNormalEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        MouseNormalEvent(Viewer*, const Param& p = {});
        virtual ~MouseNormalEvent();
        
        static void init_info();
    };
}
