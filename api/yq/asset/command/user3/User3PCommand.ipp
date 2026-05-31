////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "User3PCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::User³PCommand)

namespace yq::tachyon {
    User³PCommand::User³PCommand(const Header& h, const Algebra& _p) : User³Command(h), m_p(_p)
    {
    }
    
    User³PCommand::User³PCommand(const User³PCommand&cp, const Header&h) : 
        User³Command(cp, h), m_p(cp.m_p)
    {
    }

    User³PCommand::~User³PCommand()
    {
    }
    
    PostCPtr    User³PCommand::clone(rebind_k, const Header&h) const
    {
        return new User³PCommand(*this, h);
    }

    void User³PCommand::init_meta()
    {
        auto w = writer<User³PCommand>();
        w.description("User³ P Command");
        w.property("p", &User³PCommand::m_p);
    }
}
