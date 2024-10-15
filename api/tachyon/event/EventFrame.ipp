////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "EventFrame.hpp"

namespace yq::tachyon {

    EventFrame::EventFrame(const EventFrameOptions&options)
    {
        if(options.initial_capacity)
            m_events.reserve(options.initial_capacity);
    }
    
    EventFrame::~EventFrame()
    {
    }
    
    void                EventFrame::handle(EventPtr ep) 
    {
        if(ep){
            m_events.push_back(ep);
        }
    }
    
    std::string_view    EventFrame::description() const 
    {
        return "Container of Events in a frame";
    }
    
    std::string_view    EventFrame::name() const 
    {
        return "EventFrame";
    }
    
}
