////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/Event.hpp>
#include <tachyon/event/EventSocket.hpp>

namespace yq::tachyon {
    struct EventFrameOptions {
        //! Specify if you know approximately how many we'll initially need
        size_t  initial_capacity    = 0;
    };

    class EventFrame : public EventSocket {
    public:
    
        EventFrame(const EventFrameOptions&options={});
        ~EventFrame();

        virtual void                handle(EventPtr) override;
        virtual std::string_view    description() const override;
        virtual std::string_view    name() const override;
    
    private:
        std::vector<EventPtr>   m_events;
    };
}

