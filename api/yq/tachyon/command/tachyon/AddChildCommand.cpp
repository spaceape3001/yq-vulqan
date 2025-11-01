////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/tachyon/AddChildCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

namespace yq::tachyon {
    AddChildCommand::AddChildCommand(const Header& h, TachyonSpec par) : TachyonCommand(h), m_child(par)
    {
    }
    
    AddChildCommand::AddChildCommand(const AddChildCommand& cp, const Header& h) : 
        TachyonCommand(cp, h), m_child(cp.m_child)
    {
    }
    
    AddChildCommand::~AddChildCommand()
    {
    }
        
    PostCPtr    AddChildCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddChildCommand(*this, h);
    }

    void AddChildCommand::init_meta()
    {
        auto w = writer<AddChildCommand>();
        w.description("Set Parent Command");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddChildCommand)
