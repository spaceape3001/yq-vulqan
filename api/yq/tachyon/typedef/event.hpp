////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>

namespace yq {
    template <typename> class Ref;
    class Object;
}

namespace yq::tachyon {
    class Event;
    using EventPtr = Ref<Event>;
    
    class EventFilter;
    class EventFrame;
    class EventManager;
    class EventMapper;  // might rename to EventWizard?
    class EventSocket;
    class EventProducer;
    class EventTrigger;
    
    using EventFilterUPtr       = std::unique_ptr<EventFilter>;
    
    //using EventMapperSPtr       = std::shared_ptr<EventMapper>;
    //using EventFrameSPtr        = std::shared_ptr<EventFrame>;

    //using EventMapperSCPtr      = std::shared_ptr<const EventMapper>;
    //using EventFrameSCPtr       = std::shared_ptr<const EventFrame>;
}