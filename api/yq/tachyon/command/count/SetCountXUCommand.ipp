////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetCountXUCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetCountˣUCommand)

namespace yq::tachyon {
    SetCountˣUCommand::SetCountˣUCommand(const Header& h) : 
        CountCommand(h)
    {
    }

    SetCountˣUCommand::SetCountˣUCommand(const Header& h, unsigned v) : 
        CountCommand(h), m_x(v)
    {
    }

    SetCountˣUCommand::SetCountˣUCommand(const SetCountˣUCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetCountˣUCommand::~SetCountˣUCommand()
    {
    }

    PostCPtr    SetCountˣUCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetCountˣUCommand(*this, h);
    }
    
    void SetCountˣUCommand::init_meta()
    {
        auto w = writer<SetCountˣUCommand>();
        w.description("Set Count Command in X");
        w.property("x", &SetCountˣUCommand::m_x).tag(kTag_Log).tag(kTag_Save);
    }
}
