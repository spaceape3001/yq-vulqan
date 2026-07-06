////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "DomainCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::DomainCommand)

namespace yq::tachyon {
    DomainCommand::DomainCommand(const Header& h) : Command(h)
    {
    }
    
    DomainCommand::DomainCommand(const DomainCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    DomainCommand::~DomainCommand()
    {
    }
    
    void DomainCommand::init_meta()
    {
        auto w = writer<DomainCommand>();
        w.abstract();
        w.description("Domain Command");
    }
}
