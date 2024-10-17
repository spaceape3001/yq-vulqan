////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/Event.hpp>
#include <tachyon/event/EventSocket.hpp>
#include <unordered_set>

namespace yq::tachyon {
    struct EventFrameOptions {
        //! Specify if you know approximately how many we'll initially need
        size_t  initial_capacity    = 0;
    };

    class EventFrame : public EventSocket {
    public:
    
        EventFrame(const EventFrameOptions&options={});
        ~EventFrame();

        virtual std::string_view        description() const override;
        virtual std::string_view        name() const override;
        
        void                            add(EventPtr);
        
        void                            dispatch_all();
        
        std::vector<EventPtr>           m_events;

    protected:
        virtual void                    handle(Event&) override;
    };
}

