////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/EventProducer.hpp>
#include <yq/tachyon/event/EventSocket.hpp>

namespace yq::tachyon {
    class EventFilter : public EventSocket, public EventProducer {
    public:
        std::string_view    description() const override;
        std::string_view    name() const override;
    
        ~EventFilter();
        EventFilter(EventTrigger*);

    private:
        virtual void  handle(Event&) override final = 0;
        
        EventTrigger*   m_trigger   = nullptr;
    };
}
