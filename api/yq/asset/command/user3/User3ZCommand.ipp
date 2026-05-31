////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "User3ZCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::User³ZCommand)

namespace yq::tachyon {
    User³ZCommand::User³ZCommand(const Header& h, const Algebra& _z) : User³Command(h), m_z(_z)
    {
    }
    
    User³ZCommand::User³ZCommand(const User³ZCommand&cp, const Header&h) : 
        User³Command(cp, h), m_z(cp.m_z)
    {
    }

    User³ZCommand::~User³ZCommand()
    {
    }
    
    PostCPtr    User³ZCommand::clone(rebind_k, const Header&h) const
    {
        return new User³ZCommand(*this, h);
    }

    void User³ZCommand::init_meta()
    {
        auto w = writer<User³ZCommand>();
        w.description("User³ Z Command");
        w.property("z", &User³ZCommand::m_z);
    }
}
