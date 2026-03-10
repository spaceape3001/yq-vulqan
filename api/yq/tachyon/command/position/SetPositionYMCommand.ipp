////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionYMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionYMCommand)

namespace yq::tachyon {
    SetPositionYMCommand::SetPositionYMCommand(const Header&h, Meter y) : 
        PositionCommand(h), m_y(y)
    {
    }

    SetPositionYMCommand::SetPositionYMCommand(const SetPositionYMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetPositionYMCommand::~SetPositionYMCommand()
    {
    }
    
    PostCPtr    SetPositionYMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPositionYMCommand(*this, h);
    }

    void SetPositionYMCommand::init_meta()
    {
        auto w = writer<SetPositionYMCommand>();
        w.description("Set Position Command");
        w.property("y", &SetPositionYMCommand::y).tag(kTag_Log).tag(kTag_Save);
    }
}
