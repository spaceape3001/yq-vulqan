////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Event.hpp>

namespace yq::tachyon {
    class ViewerEvent : public Event {
        YQ_OBJECT_DECLARE(ViewerEvent, Event)
    public:
        static void init_info();
    
    protected:
        ViewerEvent(const Header&);
        ViewerEvent(const ViewerEvent&, const Header&);
        virtual ~ViewerEvent();
    
    private:
        ViewerEvent(const ViewerEvent&) = delete;
        ViewerEvent(ViewerEvent&&) = delete;
        ViewerEvent& operator=(const ViewerEvent&) = delete;
        ViewerEvent& operator=(ViewerEvent&&) = delete;
    };
}
