////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "EmptyEvent.hpp"
#include <yq/core/DelayInit.hpp>
#include <yq/tachyon/api/EventInfoWriter.hpp>

namespace yq::tachyon {
    EmptyEvent::EmptyEvent(const Param& p) : Event(p) 
    {
    }
    
    EmptyEvent::~EmptyEvent()
    {
    }
    
    void EmptyEvent::init_info()
    {
        auto w = writer<EmptyEvent>();
        w.description("Empty Event");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::EmptyEvent)
