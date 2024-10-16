////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "EventFilter.hpp"
#include <tachyon/event/Event.hpp>
#include <tachyon/event/EventTrigger.hpp>
#include <cassert>

namespace yq::tachyon {
    EventFilter::EventFilter(EventTrigger* trigger) : m_trigger(trigger)
    {
        assert(m_trigger);
    }
    
    EventFilter::~EventFilter()
    {
    }

    std::string_view    EventFilter::description() const 
    {
        return "Generic Event Filter";
    }
    
    void  EventFilter::handle(Event&evt)
    {
        if(m_trigger && m_trigger -> detect(evt)){
            publish(&evt);
        }
    }
    
    std::string_view    EventFilter::name() const 
    {
        return "EventFilter";
    }
}
