////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetCountYUCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetCountʸUCommand)

namespace yq::tachyon {
    SetCountʸUCommand::SetCountʸUCommand(const Header& h) : 
        CountCommand(h)
    {
    }

    SetCountʸUCommand::SetCountʸUCommand(const Header& h, unsigned v) : 
        CountCommand(h), m_y(v)
    {
    }

    SetCountʸUCommand::SetCountʸUCommand(const SetCountʸUCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetCountʸUCommand::~SetCountʸUCommand()
    {
    }

    PostCPtr    SetCountʸUCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetCountʸUCommand(*this, h);
    }
    
    void SetCountʸUCommand::init_meta()
    {
        auto w = writer<SetCountʸUCommand>();
        w.description("Set Count Command in Y");
        w.property("y", &SetCountʸUCommand::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
