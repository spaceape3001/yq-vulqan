////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/EventSocket.hpp>
#include <tachyon/event/EventPublisher.hpp>

namespace yq::tachyon {
    class EventCounter : public EventSocket, public EventPublisher {
    public:
    
        EventCounter();
        ~EventCounter();
    
    };
}
