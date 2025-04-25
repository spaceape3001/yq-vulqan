////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/ui/StartupCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::StartupCommand)

namespace yq::tachyon {

    StartupCommand::StartupCommand(const Header&h) : UICommand(h)
    {
    }

    StartupCommand::StartupCommand(const StartupCommand& cp, const Header& h) : UICommand(cp, h)
    {
    }
    
    StartupCommand::~StartupCommand()
    {
    }

    PostCPtr    StartupCommand::clone(rebind_k, const Header&h) const 
    {
        return new StartupCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void StartupCommand::init_info()
    {
        auto w = writer<StartupCommand>();
        w.description("Startup Command");
    }
}
