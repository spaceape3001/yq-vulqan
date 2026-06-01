////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSizeXMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeˣMCommand)

namespace yq::tachyon {
    SetMaxSizeˣMCommand::SetMaxSizeˣMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeˣMCommand::SetMaxSizeˣMCommand(const Header& h, Meter v) : 
        SizeCommand(h), m_x(v)
    {
    }

    SetMaxSizeˣMCommand::SetMaxSizeˣMCommand(const SetMaxSizeˣMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetMaxSizeˣMCommand::~SetMaxSizeˣMCommand()
    {
    }

    PostCPtr    SetMaxSizeˣMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeˣMCommand(*this, h);
    }
    
    void SetMaxSizeˣMCommand::init_meta()
    {
        auto w = writer<SetMaxSizeˣMCommand>();
        w.description("SetMax Size MCommand in X");
        w.property("x", &SetMaxSizeˣMCommand::m_x).tag(kTag_Log).tag(kTag_Save);
    }
}
