////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/tachyon/SetParentCommand.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

namespace yq::tachyon {
    SetParentCommand::SetParentCommand(const Header& h, TachyonSpec par) : TachyonCommand(h), m_parent(par)
    {
    }
    
    SetParentCommand::SetParentCommand(const SetParentCommand& cp, const Header& h) : TachyonCommand(cp, h), m_parent(cp.m_parent)
    {
    }
    
    SetParentCommand::~SetParentCommand()
    {
    }
        
    PostCPtr    SetParentCommand::clone(rebind_k, const Header& h) const 
    {
        return new SetParentCommand(*this, h);
    }

    void SetParentCommand::init_info()
    {
        auto w = writer<SetParentCommand>();
        w.description("Set Parent Command");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetParentCommand)
