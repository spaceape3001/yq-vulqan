////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSizeXCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeˣCMCommand)

namespace yq::tachyon {
    SetSizeˣCMCommand::SetSizeˣCMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeˣCMCommand::SetSizeˣCMCommand(const Header& h, Centimeter v) : 
        SizeCommand(h), m_x(v)
    {
    }

    SetSizeˣCMCommand::SetSizeˣCMCommand(const SetSizeˣCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetSizeˣCMCommand::~SetSizeˣCMCommand()
    {
    }

    PostCPtr    SetSizeˣCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeˣCMCommand(*this, h);
    }
    
    void SetSizeˣCMCommand::init_meta()
    {
        auto w = writer<SetSizeˣCMCommand>();
        w.description("Set Size CMCommand in X");
        w.property("x", &SetSizeˣCMCommand::m_x).tag(kTag_Log).tag(kTag_Save);
    }
}
