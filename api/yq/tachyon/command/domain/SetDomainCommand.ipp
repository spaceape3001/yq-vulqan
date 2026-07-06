////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetDomainCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

namespace yq::tachyon {
    SetDomainCommand::SetDomainCommand(const Header& h, DomainID par) : DomainCommand(h), m_domain(par)
    {
    }
    
    SetDomainCommand::SetDomainCommand(const SetDomainCommand& cp, const Header& h) : DomainCommand(cp, h), m_domain(cp.m_domain)
    {
    }
    
    SetDomainCommand::~SetDomainCommand()
    {
    }
        
    PostCPtr    SetDomainCommand::clone(rebind_k, const Header& h) const 
    {
        return new SetDomainCommand(*this, h);
    }

    void SetDomainCommand::init_meta()
    {
        auto w = writer<SetDomainCommand>();
        w.description("Set Domain Command");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetDomainCommand)
