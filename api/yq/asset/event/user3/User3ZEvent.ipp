////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "User3ZEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::User³ZEvent)

namespace yq::tachyon {
    User³ZEvent::User³ZEvent(const Header& h, const Algebra& _z) : User³Event(h), m_z(_z)
    {
    }
    
    User³ZEvent::User³ZEvent(const User³ZEvent&cp, const Header&h) : 
        User³Event(cp, h), m_z(cp.m_z)
    {
    }

    User³ZEvent::~User³ZEvent()
    {
    }
    
    PostCPtr    User³ZEvent::clone(rebind_k, const Header&h) const
    {
        return new User³ZEvent(*this, h);
    }

    void User³ZEvent::init_meta()
    {
        auto w = writer<User³ZEvent>();
        w.description("User³ Z Event");
        w.property("z", &User³ZEvent::m_z);
    }
}
