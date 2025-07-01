////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/controller/DisableCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::DisableCommand)

namespace yq::tachyon {

    DisableCommand::DisableCommand(const Header&h) : ControllerCommand(h)
    {
    }
    
    DisableCommand::DisableCommand(const DisableCommand& cp, const Header&h) : ControllerCommand(cp, h)
    {
    }
    
    DisableCommand::~DisableCommand()
    {
    }
    
    PostCPtr    DisableCommand::clone(rebind_k, const Header&h) const 
    {
        return new DisableCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void DisableCommand::init_info()
    {
        auto w = writer<DisableCommand>();
        w.description("Disable Command");
    }
}
