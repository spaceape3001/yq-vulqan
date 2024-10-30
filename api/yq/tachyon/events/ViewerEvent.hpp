////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Event.hpp>

namespace yq::tachyon {
    class Viewer;

    class ViewerEventInfo : public post::EventInfo {
    public:
        ViewerEventInfo(std::string_view zName, post::EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class ViewerEvent : public post::Event {
        YQ_OBJECT_INFO(ViewerEventInfo)
        YQ_OBJECT_DECLARE(ViewerEvent, post::Event)
    public:
    
        struct Param : public post::Event::Param {
        };
    
        ViewerEvent(Viewer*, const Param& p = {});
        virtual ~ViewerEvent();
        
        Viewer*     viewer() const { return m_viewer; }
        
    private:
        Viewer*     m_viewer    = nullptr;
    };
}
