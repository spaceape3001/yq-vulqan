////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "User3YEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::User³YEvent)

namespace yq::tachyon {
    User³YEvent::User³YEvent(const Header& h, const Algebra& _y) : User³Event(h), m_y(_y)
    {
    }
    
    User³YEvent::User³YEvent(const User³YEvent&cp, const Header&h) : 
        User³Event(cp, h), m_y(cp.m_y)
    {
    }

    User³YEvent::~User³YEvent()
    {
    }
    
    PostCPtr    User³YEvent::clone(rebind_k, const Header&h) const
    {
        return new User³YEvent(*this, h);
    }

    void User³YEvent::init_meta()
    {
        auto w = writer<User³YEvent>();
        w.description("User³ Y Event");
        w.property("y", &User³YEvent::m_y);
    }
}
