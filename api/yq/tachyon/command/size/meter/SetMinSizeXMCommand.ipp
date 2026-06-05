////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSizeXMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeˣMCommand)

namespace yq::tachyon {
    SetMinSizeˣMCommand::SetMinSizeˣMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeˣMCommand::SetMinSizeˣMCommand(const Header& h, Meter v) : 
        SizeCommand(h), m_x(v)
    {
    }

    SetMinSizeˣMCommand::SetMinSizeˣMCommand(const SetMinSizeˣMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetMinSizeˣMCommand::~SetMinSizeˣMCommand()
    {
    }

    PostCPtr    SetMinSizeˣMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeˣMCommand(*this, h);
    }
    
    void SetMinSizeˣMCommand::init_meta()
    {
        auto w = writer<SetMinSizeˣMCommand>();
        w.description("SetMin Size MCommand in X");
        w.property("x", &SetMinSizeˣMCommand::m_x).tag(kTag_Log).tag(kTag_Save);
    }
}
