////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/post/Event.hpp>
#include <yq/tachyon/core/TachyonBind.hpp>

namespace yq::tachyon {
    class Tachyon;

    class TachyonEventInfo : public EventInfo {
    public:
        TachyonEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class TachyonEvent : public Event, public TachyonBind {
        YQ_OBJECT_INFO(TachyonEventInfo)
        YQ_OBJECT_DECLARE(TachyonEvent, Event)
    public:
    
        struct Param : public Event::Param {
        };
    
        TachyonEvent(Tachyon*, const Param& p = {});
        virtual ~TachyonEvent();
        
        static void init_info();
    };
}
