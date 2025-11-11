////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/controller/EnableCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

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

    void EnableCommand::init_meta()
    {
        auto w = writer<EnableCommand>();
        w.description("Enable Command");
    }
}
