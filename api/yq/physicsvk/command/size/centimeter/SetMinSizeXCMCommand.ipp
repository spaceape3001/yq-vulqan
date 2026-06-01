////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSizeXCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeˣCMCommand)

namespace yq::tachyon {
    SetMinSizeˣCMCommand::SetMinSizeˣCMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeˣCMCommand::SetMinSizeˣCMCommand(const Header& h, Centimeter v) : 
        SizeCommand(h), m_x(v)
    {
    }

    SetMinSizeˣCMCommand::SetMinSizeˣCMCommand(const SetMinSizeˣCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetMinSizeˣCMCommand::~SetMinSizeˣCMCommand()
    {
    }

    PostCPtr    SetMinSizeˣCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeˣCMCommand(*this, h);
    }
    
    void SetMinSizeˣCMCommand::init_meta()
    {
        auto w = writer<SetMinSizeˣCMCommand>();
        w.description("SetMin Size CMCommand in X");
        w.property("x", &SetMinSizeˣCMCommand::m_x).tag(kTag_Log).tag(kTag_Save);
    }
}
