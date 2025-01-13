////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/SimCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

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
    
    void SimCommand::init_info()
    {
        auto w = writer<SimCommand>();
        w.abstract();
        w.description("Sim Command");
    }
}
