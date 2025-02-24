////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/tachyon/RemoveChildCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

namespace yq::tachyon {
    RemoveChildCommand::RemoveChildCommand(const Header& h, TachyonSpec par) : TachyonCommand(h), m_child(par)
    {
    }
    
    RemoveChildCommand::RemoveChildCommand(const RemoveChildCommand& cp, const Header& h) : 
        TachyonCommand(cp, h), m_child(cp.m_child)
    {
    }
    
    RemoveChildCommand::~RemoveChildCommand()
    {
    }
        
    PostCPtr    RemoveChildCommand::clone(rebind_k, const Header& h) const 
    {
        return new RemoveChildCommand(*this, h);
    }

    void RemoveChildCommand::init_info()
    {
        auto w = writer<RemoveChildCommand>();
        w.description("Set Parent Command");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::RemoveChildCommand)
