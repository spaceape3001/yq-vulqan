////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "User3REvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::User³REvent)

namespace yq::tachyon {
    User³REvent::User³REvent(const Header& h, const Algebra& _r) : User³Event(h), m_r(_r)
    {
    }
    
    User³REvent::User³REvent(const User³REvent&cp, const Header&h) : 
        User³Event(cp, h), m_r(cp.m_r)
    {
    }

    User³REvent::~User³REvent()
    {
    }
    
    PostCPtr    User³REvent::clone(rebind_k, const Header&h) const
    {
        return new User³REvent(*this, h);
    }

    void User³REvent::init_meta()
    {
        auto w = writer<User³REvent>();
        w.description("User³ R Event");
        w.property("r", &User³REvent::m_r);
    }
}
