////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "User3YCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::User³YCommand)

namespace yq::tachyon {
    User³YCommand::User³YCommand(const Header& h, const Algebra& _y) : User³Command(h), m_y(_y)
    {
    }
    
    User³YCommand::User³YCommand(const User³YCommand&cp, const Header&h) : 
        User³Command(cp, h), m_y(cp.m_y)
    {
    }

    User³YCommand::~User³YCommand()
    {
    }
    
    PostCPtr    User³YCommand::clone(rebind_k, const Header&h) const
    {
        return new User³YCommand(*this, h);
    }

    void User³YCommand::init_meta()
    {
        auto w = writer<User³YCommand>();
        w.description("User³ Y Command");
        w.property("y", &User³YCommand::m_y);
    }
}
