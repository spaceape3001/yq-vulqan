////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition2MCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition2MCommand)

namespace yq::tachyon {
    SetPosition2MCommand::SetPosition2MCommand(const Header& h, const Meter2D& v) : 
        PositionCommand(h), m_position(v)
    {
    }

    SetPosition2MCommand::SetPosition2MCommand(const SetPosition2MCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }
    
    SetPosition2MCommand::~SetPosition2MCommand()
    {
    }

    PostCPtr    SetPosition2MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition2MCommand(*this, h);
    }
    
    void SetPosition2MCommand::init_meta()
    {
        auto w = writer<SetPosition2MCommand>();
        w.description("Set Position Command");
        w.property("x", &SetPosition2MCommand::x).tag(kTag_Log);
        w.property("y", &SetPosition2MCommand::y).tag(kTag_Log);
        w.property("position", &SetPosition2MCommand::m_position).tag(kTag_Save);
    }
}
