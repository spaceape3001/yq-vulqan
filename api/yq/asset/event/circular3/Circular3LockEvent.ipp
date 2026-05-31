////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Circular3LockEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Circular³LockEvent)

namespace yq::tachyon {
    Circular³LockEvent::Circular³LockEvent(const Header& h, bool _lock) : Circular³Event(h), m_lock(_lock)
    {
    }
    
    Circular³LockEvent::Circular³LockEvent(const Circular³LockEvent&cp, const Header&h) : 
        Circular³Event(cp, h), m_lock(cp.m_lock)
    {
    }

    Circular³LockEvent::~Circular³LockEvent()
    {
    }
    
    PostCPtr    Circular³LockEvent::clone(rebind_k, const Header&h) const
    {
        return new Circular³LockEvent(*this, h);
    }

    void Circular³LockEvent::init_meta()
    {
        auto w = writer<Circular³LockEvent>();
        w.description("Circular³ Lock Event");
        w.property("lock", &Circular³LockEvent::m_lock);
    }
}
