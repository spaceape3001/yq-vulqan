////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionXCMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionˣCMCommand)

namespace yq::tachyon {
    SetPositionˣCMCommand::SetPositionˣCMCommand(const Header&h, Centimeter x) : 
        PositionCommand(h), m_x(x)
    {
    }
    
    SetPositionˣCMCommand::SetPositionˣCMCommand(const SetPositionˣCMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_x(cp.m_x)
    {
    }

    SetPositionˣCMCommand::~SetPositionˣCMCommand()
    {
    }

    PostCPtr    SetPositionˣCMCommand::clone(rebind_k, const Header& h) const
    {
        return new SetPositionˣCMCommand(*this, h);
    }
    
    void SetPositionˣCMCommand::init_meta()
    {
        auto w = writer<SetPositionˣCMCommand>();
        w.description("Set Position Command");
        w.property("x", &SetPositionˣCMCommand::x).tag(kTag_Log).tag(kTag_Save);
    }
}
