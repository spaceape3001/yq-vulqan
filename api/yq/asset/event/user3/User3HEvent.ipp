////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "User3HEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::User³HEvent)

namespace yq::tachyon {
    User³HEvent::User³HEvent(const Header& h, const Algebra& _x) : User³Event(h), m_h(_x)
    {
    }
    
    User³HEvent::User³HEvent(const User³HEvent&cp, const Header&h) : 
        User³Event(cp, h), m_h(cp.m_h)
    {
    }

    User³HEvent::~User³HEvent()
    {
    }
    
    PostCPtr    User³HEvent::clone(rebind_k, const Header&h) const
    {
        return new User³HEvent(*this, h);
    }

    void User³HEvent::init_meta()
    {
        auto w = writer<User³HEvent>();
        w.description("User³ H Event");
        w.property("h", &User³HEvent::m_h);
    }
}
