////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SimCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SimCommand)

namespace yq::tachyon {
    SimCommand::SimCommand(const Header& h) : Command(h)
    {
    }
    
    SimCommand::SimCommand(const SimCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    SimCommand::~SimCommand()
    {
    }
    
    void SimCommand::init_meta()
    {
        auto w = writer<SimCommand>();
        w.abstract();
        w.description("Sim Command");
    }
}
