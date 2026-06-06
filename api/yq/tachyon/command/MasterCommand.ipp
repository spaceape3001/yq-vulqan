////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MasterCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MasterCommand)

namespace yq::tachyon {
    MasterCommand::MasterCommand(const Header& h) : Command(h)
    {
    }
    
    MasterCommand::MasterCommand(const MasterCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    MasterCommand::~MasterCommand()
    {
    }
    
    void MasterCommand::init_meta()
    {
        auto w = writer<MasterCommand>();
        w.abstract();
        w.description("Master Command");
    }
}
