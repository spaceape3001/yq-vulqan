////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Event.hpp>
#include <yq/tachyon/viewer/ViewerBind.hpp>

namespace yq::tachyon {
    class WindowEventInfo : public post::EventInfo {
    public:
        WindowEventInfo(std::string_view zName, post::EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class WindowEvent : public post::Event, public ViewerBind {
        YQ_OBJECT_INFO(WindowEventInfo)
        YQ_OBJECT_DECLARE(WindowEvent, post::Event)
    public:
    
        struct Param : public post::Event::Param {
        };
    
        WindowEvent(Viewer*, const Param& p = {});
        virtual ~WindowEvent();
        
        static void init_info();
    };
}
