////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionYMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionʸMCommand)

namespace yq::tachyon {
    SetPositionʸMCommand::SetPositionʸMCommand(const Header&h, Meter y) : 
        PositionCommand(h), m_y(y)
    {
    }

    SetPositionʸMCommand::SetPositionʸMCommand(const SetPositionʸMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetPositionʸMCommand::~SetPositionʸMCommand()
    {
    }
    
    PostCPtr    SetPositionʸMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPositionʸMCommand(*this, h);
    }

    void SetPositionʸMCommand::init_meta()
    {
        auto w = writer<SetPositionʸMCommand>();
        w.description("Set Position Command");
        w.property("y", &SetPositionʸMCommand::y).tag(kTag_Log).tag(kTag_Save);
    }
}
