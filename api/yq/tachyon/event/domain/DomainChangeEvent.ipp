////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "DomainChangeEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::DomainChangeEvent)

namespace yq::tachyon {

    DomainChangeEvent::DomainChangeEvent(const Header&h, TypedID from, TypedID to) : DomainEvent(h), m_from(from), m_to(to)
    {
    }

    DomainChangeEvent::DomainChangeEvent(const DomainChangeEvent& cp, const Header& h) : 
        DomainEvent(cp, h), m_from(cp.m_from), m_to(cp.m_to)
    {
    }
    
    DomainChangeEvent::~DomainChangeEvent()
    {
    }

    PostCPtr    DomainChangeEvent::clone(rebind_k, const Header&h) const 
    {
        return new DomainChangeEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void DomainChangeEvent::init_meta()
    {
        auto w = writer<DomainChangeEvent>();
        w.description("DomainChange Event");
    }
}
