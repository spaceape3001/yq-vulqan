////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/controller/EnableCommand.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::EnableCommand)

namespace yq::tachyon {

    EnableCommand::EnableCommand(const Header&h) : ControllerCommand(h)
    {
    }
    
    EnableCommand::EnableCommand(const EnableCommand& cp, const Header&h) : ControllerCommand(cp, h)
    {
    }
    
    EnableCommand::~EnableCommand()
    {
    }

    PostCPtr    EnableCommand::clone(rebind_k, const Header&h) const 
    {
        return new EnableCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void EnableCommand::init_info()
    {
        auto w = writer<EnableCommand>();
        w.description("Enable Command");
    }
}
