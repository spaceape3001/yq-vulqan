////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MassCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MassCommand)

namespace yq::tachyon {
    MassCommand::MassCommand(const Header& h) : Command(h)
    {
    }
    
    MassCommand::MassCommand(const MassCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    MassCommand::~MassCommand()
    {
    }
    
    void MassCommand::init_meta()
    {
        auto w = writer<MassCommand>();
        w.abstract();
        w.description("Mass Command");
    }
}
