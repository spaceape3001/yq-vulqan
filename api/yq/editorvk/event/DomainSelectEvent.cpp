////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "DomainSelectEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::DomainSelectEvent)

namespace yq::tachyon {

    DomainSelectEvent::DomainSelectEvent(const Header& h, DomainID c) : EditorEvent(h), m_domain(c)
    {
    }

    DomainSelectEvent::DomainSelectEvent(const DomainSelectEvent&cp, const Header&h) : 
        EditorEvent(cp, h), m_domain(cp.m_domain)
    {
    }

    DomainSelectEvent::~DomainSelectEvent()
    {
    }


    PostCPtr    DomainSelectEvent::clone(rebind_k, const Header&h) const 
    {
        return new DomainSelectEvent(*this, h);
    }

    void DomainSelectEvent::init_meta()
    {
        auto w = writer<DomainSelectEvent>();
        w.description("Domain Selection Event");
    }

}
