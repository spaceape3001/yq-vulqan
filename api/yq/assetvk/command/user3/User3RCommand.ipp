////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "User3RCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::User³RCommand)

namespace yq::tachyon {
    User³RCommand::User³RCommand(const Header& h, const Algebra& _r) : User³Command(h), m_r(_r)
    {
    }
    
    User³RCommand::User³RCommand(const User³RCommand&cp, const Header&h) : 
        User³Command(cp, h), m_r(cp.m_r)
    {
    }

    User³RCommand::~User³RCommand()
    {
    }
    
    PostCPtr    User³RCommand::clone(rebind_k, const Header&h) const
    {
        return new User³RCommand(*this, h);
    }

    void User³RCommand::init_meta()
    {
        auto w = writer<User³RCommand>();
        w.description("User³ R Command");
        w.property("r", &User³RCommand::m_r);
    }
}
