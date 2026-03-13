////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetCountXCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetCountˣCommand)

namespace yq::tachyon {
    SetCountˣCommand::SetCountˣCommand(const Header& h) : 
        CountCommand(h)
    {
    }

    SetCountˣCommand::SetCountˣCommand(const Header& h, unsigned v) : 
        CountCommand(h), m_x(v)
    {
    }

    SetCountˣCommand::SetCountˣCommand(const SetCountˣCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetCountˣCommand::~SetCountˣCommand()
    {
    }

    PostCPtr    SetCountˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetCountˣCommand(*this, h);
    }
    
    void SetCountˣCommand::init_meta()
    {
        auto w = writer<SetCountˣCommand>();
        w.description("Set Count Command in X");
        w.property("x", &SetCountˣCommand::m_x).tag(kTag_Log).tag(kTag_Save);
    }
}
