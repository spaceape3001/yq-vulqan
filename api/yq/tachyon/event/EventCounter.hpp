////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/EventSocket.hpp>
#include <yq/tachyon/event/EventPublisher.hpp>

namespace yq::tachyon {
    class EventCounter : public EventSocket, public EventPublisher {
    public:
    
        EventCounter();
        ~EventCounter();
    
    };
}
