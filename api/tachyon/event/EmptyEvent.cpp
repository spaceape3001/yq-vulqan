////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/EmptyEvent.hpp>
#include <yq/core/DelayInit.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {
    EmptyEvent::EmptyEvent(const Header& h) : Event(h) 
    {
    }
    
    EmptyEvent::EmptyEvent(const EmptyEvent& cp, const Header& h) : Event(cp, h) 
    {
    }

    EmptyEvent::~EmptyEvent()
    {
    }

    PostCPtr    EmptyEvent::clone(rebind_k, const Header& h) const
    {
        return new EmptyEvent(*this, h);
    }
    
    void EmptyEvent::init_meta()
    {
        auto w = writer<EmptyEvent>();
        w.description("Empty Event");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::EmptyEvent)
