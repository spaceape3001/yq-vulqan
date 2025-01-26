////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/controller/UncontrolCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UncontrolCommand)

namespace yq::tachyon {

    UncontrolCommand::UncontrolCommand(const Header&h, TypedID t) : 
        ControllerCommand(h), m_tachyon(t)
    {
    }
    
    UncontrolCommand::UncontrolCommand(const UncontrolCommand& cp, const Header&h) : 
        ControllerCommand(cp, h), m_tachyon(cp.m_tachyon)
    {
    }
    
    UncontrolCommand::~UncontrolCommand()
    {
    }
    
    PostCPtr    UncontrolCommand::clone(rebind_k, const Header&h) const
    {
        return new UncontrolCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void UncontrolCommand::init_info()
    {
        auto w = writer<UncontrolCommand>();
        w.description("Uncontrol Command");
    }
}
