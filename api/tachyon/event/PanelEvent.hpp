////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QPanelLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Event.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class PanelEvent : public Event {
        YQ_OBJECT_DECLARE(PanelEvent, Event)
    public:
    
        static void init_meta();

    protected:
        PanelEvent(const Header&);
        PanelEvent(const PanelEvent&, const Header&);
        ~PanelEvent();
    
    private:
        PanelEvent(const PanelEvent&) = delete;
        PanelEvent(PanelEvent&&) = delete;
        PanelEvent& operator=(const PanelEvent&) = delete;
        PanelEvent& operator=(PanelEvent&&) = delete;
    };
}
