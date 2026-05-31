////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "User3PEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::User³PEvent)

namespace yq::tachyon {
    User³PEvent::User³PEvent(const Header& h, const Algebra& _p) : User³Event(h), m_p(_p)
    {
    }
    
    User³PEvent::User³PEvent(const User³PEvent&cp, const Header&h) : 
        User³Event(cp, h), m_p(cp.m_p)
    {
    }

    User³PEvent::~User³PEvent()
    {
    }
    
    PostCPtr    User³PEvent::clone(rebind_k, const Header&h) const
    {
        return new User³PEvent(*this, h);
    }

    void User³PEvent::init_meta()
    {
        auto w = writer<User³PEvent>();
        w.description("User³ P Event");
        w.property("p", &User³PEvent::m_p);
    }
}
