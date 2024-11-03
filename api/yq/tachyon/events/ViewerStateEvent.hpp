////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/ViewerEvent.hpp>
#include <yq/tachyon/ViewerState.hpp>

namespace yq::tachyon {
    class ViewerStateEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(ViewerStateEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        ViewerStateEvent(Viewer*, const ViewerState&, const Param& p = {});
        virtual ~ViewerStateEvent();
        
        static void init_info();
        
        const ViewerState&  state() const { return m_state; }
        
    private:
        const ViewerState   m_state;
    };
}
