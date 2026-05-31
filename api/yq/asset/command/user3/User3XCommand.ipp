////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "User3XCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::User³XCommand)

namespace yq::tachyon {
    User³XCommand::User³XCommand(const Header& h, const Algebra& _x) : User³Command(h), m_x(_x)
    {
    }
    
    User³XCommand::User³XCommand(const User³XCommand&cp, const Header&h) : 
        User³Command(cp, h), m_x(cp.m_x)
    {
    }

    User³XCommand::~User³XCommand()
    {
    }
    
    PostCPtr    User³XCommand::clone(rebind_k, const Header&h) const
    {
        return new User³XCommand(*this, h);
    }

    void User³XCommand::init_meta()
    {
        auto w = writer<User³XCommand>();
        w.description("User³ X Command");
        w.property("x", &User³XCommand::m_x);
    }
}
