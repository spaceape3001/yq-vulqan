////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>
#include <yq/tachyon/viewer/ViewerBind.hpp>

namespace yq::tachyon {
    class Viewer;

    class ViewerEventInfo : public EventInfo {
    public:
        ViewerEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class ViewerEvent : public Event, public ViewerBind {
        YQ_OBJECT_INFO(ViewerEventInfo)
        YQ_OBJECT_DECLARE(ViewerEvent, Event)
    public:
    
        struct Param : public Event::Param {
        };
    
        ViewerEvent(Viewer*, const Param& p = {});
        virtual ~ViewerEvent();
        
        static void init_info();
    };
}
