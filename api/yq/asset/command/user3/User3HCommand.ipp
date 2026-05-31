////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "User3HCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::User³HCommand)

namespace yq::tachyon {
    User³HCommand::User³HCommand(const Header& h, const Algebra& _x) : User³Command(h), m_h(_x)
    {
    }
    
    User³HCommand::User³HCommand(const User³HCommand&cp, const Header&h) : 
        User³Command(cp, h), m_h(cp.m_h)
    {
    }

    User³HCommand::~User³HCommand()
    {
    }
    
    PostCPtr    User³HCommand::clone(rebind_k, const Header&h) const
    {
        return new User³HCommand(*this, h);
    }

    void User³HCommand::init_meta()
    {
        auto w = writer<User³HCommand>();
        w.description("User³ H Command");
        w.property("h", &User³HCommand::m_h);
    }
}
