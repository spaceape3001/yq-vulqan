////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "EventTrigger.hpp"

namespace yq::tachyon {

    std::string_view    EventTrigger::description() const 
    {
        return "Generic event trigger";
    }
    
    std::string_view    EventTrigger::name() const 
    {
        return "EventTrigger";
    }

    EventTrigger::~EventTrigger()
    {
    }
    
    EventTrigger::EventTrigger()
    {
    }
}

