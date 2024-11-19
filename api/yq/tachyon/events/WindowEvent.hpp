////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>
#include <yq/tachyon/api/ViewerBind.hpp>

namespace yq::tachyon {
    class WindowEventInfo : public EventInfo {
    public:
        WindowEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class WindowEvent : public Event, public ViewerBind {
        YQ_OBJECT_INFO(WindowEventInfo)
        YQ_OBJECT_DECLARE(WindowEvent, Event)
    public:
    
        struct Param : public Event::Param {
        };
    
        WindowEvent(Viewer*, const Param& p = {});
        virtual ~WindowEvent();
        
        static void init_info();
    };
}
