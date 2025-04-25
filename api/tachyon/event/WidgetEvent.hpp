////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Event.hpp>

namespace yq::tachyon {
    class WidgetEvent : public Event {
        YQ_OBJECT_DECLARE(WidgetEvent, Event)
    public:
    
        static void init_info();

    protected:
        WidgetEvent(const Header&);
        WidgetEvent(const WidgetEvent&, const Header&);
        virtual ~WidgetEvent();

    private:
        WidgetEvent(const WidgetEvent&) = delete;
        WidgetEvent(WidgetEvent&&) = delete;
        WidgetEvent& operator=(const WidgetEvent&) = delete;
        WidgetEvent& operator=(WidgetEvent&&) = delete;
    };

}
