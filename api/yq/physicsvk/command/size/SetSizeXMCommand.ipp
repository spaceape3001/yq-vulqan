////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSizeXMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeˣMCommand)

namespace yq::tachyon {
    SetSizeˣMCommand::SetSizeˣMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeˣMCommand::SetSizeˣMCommand(const Header& h, Meter v) : 
        SizeCommand(h), m_x(v)
    {
    }

    SetSizeˣMCommand::SetSizeˣMCommand(const SetSizeˣMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetSizeˣMCommand::~SetSizeˣMCommand()
    {
    }

    PostCPtr    SetSizeˣMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeˣMCommand(*this, h);
    }
    
    void SetSizeˣMCommand::init_meta()
    {
        auto w = writer<SetSizeˣMCommand>();
        w.description("Set Size MCommand in X");
        w.property("x", &SetSizeˣMCommand::m_x).tag(kTag_Log).tag(kTag_Save);
    }
}
