////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSizeXCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeˣCMCommand)

namespace yq::tachyon {
    SetMaxSizeˣCMCommand::SetMaxSizeˣCMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeˣCMCommand::SetMaxSizeˣCMCommand(const Header& h, Centimeter v) : 
        SizeCommand(h), m_x(v)
    {
    }

    SetMaxSizeˣCMCommand::SetMaxSizeˣCMCommand(const SetMaxSizeˣCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetMaxSizeˣCMCommand::~SetMaxSizeˣCMCommand()
    {
    }

    PostCPtr    SetMaxSizeˣCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeˣCMCommand(*this, h);
    }
    
    void SetMaxSizeˣCMCommand::init_meta()
    {
        auto w = writer<SetMaxSizeˣCMCommand>();
        w.description("SetMax Size CMCommand in X");
        w.property("x", &SetMaxSizeˣCMCommand::m_x).tag(kTag_Log).tag(kTag_Save);
    }
}
