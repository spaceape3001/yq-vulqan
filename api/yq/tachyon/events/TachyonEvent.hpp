////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Event.hpp>
#include <yq/tachyon/TachyonBind.hpp>

namespace yq::tachyon {
    class Tachyon;

    class TachyonEventInfo : public post::EventInfo {
    public:
        TachyonEventInfo(std::string_view zName, post::EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class TachyonEvent : public post::Event, public TachyonBind {
        YQ_OBJECT_INFO(TachyonEventInfo)
        YQ_OBJECT_DECLARE(TachyonEvent, post::Event)
    public:
    
        struct Param : public post::Event::Param {
        };
    
        TachyonEvent(Tachyon*, const Param& p = {});
        virtual ~TachyonEvent();
        
        static void init_info();
    };
}
