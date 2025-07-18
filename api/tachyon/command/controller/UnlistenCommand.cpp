////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/controller/UnlistenCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

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

    void UnlistenCommand::init_meta()
    {
        auto w = writer<UnlistenCommand>();
        w.description("Unlisten Command");
    }
}
