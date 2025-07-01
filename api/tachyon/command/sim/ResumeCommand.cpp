////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/sim/ResumeCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ResumeCommand)

namespace yq::tachyon {

    ResumeCommand::ResumeCommand(const Header&h) : SimCommand(h)
    {
    }

    ResumeCommand::ResumeCommand(const ResumeCommand& cp, const Header& h) : SimCommand(cp, h)
    {
    }
    
    ResumeCommand::~ResumeCommand()
    {
    }

    PostCPtr    ResumeCommand::clone(rebind_k, const Header&h) const 
    {
        return new ResumeCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ResumeCommand::init_info()
    {
        auto w = writer<ResumeCommand>();
        w.description("Resume Command");
    }
}
