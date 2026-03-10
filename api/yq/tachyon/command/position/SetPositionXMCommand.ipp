////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionXMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionˣMCommand)

namespace yq::tachyon {
    SetPositionˣMCommand::SetPositionˣMCommand(const Header&h, Meter x) : 
        PositionCommand(h), m_x(x)
    {
    }
    
    SetPositionˣMCommand::SetPositionˣMCommand(const SetPositionˣMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_x(cp.m_x)
    {
    }

    SetPositionˣMCommand::~SetPositionˣMCommand()
    {
    }

    PostCPtr    SetPositionˣMCommand::clone(rebind_k, const Header& h) const
    {
        return new SetPositionˣMCommand(*this, h);
    }
    
    void SetPositionˣMCommand::init_meta()
    {
        auto w = writer<SetPositionˣMCommand>();
        w.description("Set Position Command");
        w.property("x", &SetPositionˣMCommand::x).tag(kTag_Log).tag(kTag_Save);
    }
}
