////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "User3XEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::User³XEvent)

namespace yq::tachyon {
    User³XEvent::User³XEvent(const Header& h, const Algebra& _x) : User³Event(h), m_x(_x)
    {
    }
    
    User³XEvent::User³XEvent(const User³XEvent&cp, const Header&h) : 
        User³Event(cp, h), m_x(cp.m_x)
    {
    }

    User³XEvent::~User³XEvent()
    {
    }
    
    PostCPtr    User³XEvent::clone(rebind_k, const Header&h) const
    {
        return new User³XEvent(*this, h);
    }

    void User³XEvent::init_meta()
    {
        auto w = writer<User³XEvent>();
        w.description("User³ X Event");
        w.property("x", &User³XEvent::m_x);
    }
}
