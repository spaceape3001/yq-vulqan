////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/ui/ShutdownCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ShutdownCommand)

namespace yq::tachyon {

    ShutdownCommand::ShutdownCommand(const Header&h) : UICommand(h)
    {
    }

    ShutdownCommand::ShutdownCommand(const ShutdownCommand& cp, const Header& h) : UICommand(cp, h)
    {
    }
    
    ShutdownCommand::~ShutdownCommand()
    {
    }

    PostCPtr    ShutdownCommand::clone(rebind_k, const Header&h) const 
    {
        return new ShutdownCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ShutdownCommand::init_info()
    {
        auto w = writer<ShutdownCommand>();
        w.description("Shutdown Command");
    }
}
