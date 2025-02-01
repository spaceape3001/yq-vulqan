////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/sim/PauseCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PauseCommand)

namespace yq::tachyon {

    PauseCommand::PauseCommand(const Header&h) : SimCommand(h)
    {
    }

    PauseCommand::PauseCommand(const PauseCommand& cp, const Header& h) : SimCommand(cp, h)
    {
    }
    
    PauseCommand::~PauseCommand()
    {
    }

    PostCPtr    PauseCommand::clone(rebind_k, const Header&h) const 
    {
        return new PauseCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void PauseCommand::init_info()
    {
        auto w = writer<PauseCommand>();
        w.description("Pause Command");
    }
}
