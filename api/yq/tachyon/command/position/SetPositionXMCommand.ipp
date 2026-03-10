////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionXMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionXMCommand)

namespace yq::tachyon {
    SetPositionXMCommand::SetPositionXMCommand(const Header&h, Meter x) : 
        PositionCommand(h), m_x(x)
    {
    }
    
    SetPositionXMCommand::SetPositionXMCommand(const SetPositionXMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_x(cp.m_x)
    {
    }

    SetPositionXMCommand::~SetPositionXMCommand()
    {
    }

    PostCPtr    SetPositionXMCommand::clone(rebind_k, const Header& h) const
    {
        return new SetPositionXMCommand(*this, h);
    }
    
    void SetPositionXMCommand::init_meta()
    {
        auto w = writer<SetPositionXMCommand>();
        w.description("Set Position Command");
        w.property("x", &SetPositionXMCommand::x).tag(kTag_Log).tag(kTag_Save);
    }
}
