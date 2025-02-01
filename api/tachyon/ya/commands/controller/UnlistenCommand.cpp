////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/controller/UnlistenCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UnlistenCommand)

namespace yq::tachyon {

    UnlistenCommand::UnlistenCommand(const Header&h, TypedID t) : 
        ControllerCommand(h), m_tachyon(t)
    {
    }
    
    UnlistenCommand::UnlistenCommand(const UnlistenCommand& cp, const Header& h) : 
        ControllerCommand(cp, h), m_tachyon(cp.m_tachyon)
    {
    }
    
    UnlistenCommand::~UnlistenCommand()
    {
    }
    
    PostCPtr    UnlistenCommand::clone(rebind_k, const Header&h) const
    {
        return new UnlistenCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void UnlistenCommand::init_info()
    {
        auto w = writer<UnlistenCommand>();
        w.description("Unlisten Command");
    }
}
