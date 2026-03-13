////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetCountYCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetCountʸCommand)

namespace yq::tachyon {
    SetCountʸCommand::SetCountʸCommand(const Header& h) : 
        CountCommand(h)
    {
    }

    SetCountʸCommand::SetCountʸCommand(const Header& h, unsigned v) : 
        CountCommand(h), m_y(v)
    {
    }

    SetCountʸCommand::SetCountʸCommand(const SetCountʸCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetCountʸCommand::~SetCountʸCommand()
    {
    }

    PostCPtr    SetCountʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetCountʸCommand(*this, h);
    }
    
    void SetCountʸCommand::init_meta()
    {
        auto w = writer<SetCountʸCommand>();
        w.description("Set Count Command in Y");
        w.property("y", &SetCountʸCommand::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
