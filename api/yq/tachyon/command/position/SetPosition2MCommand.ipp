////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition2MCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition²MCommand)

namespace yq::tachyon {
    SetPosition²MCommand::SetPosition²MCommand(const Header& h, const Meter2D& v) : 
        PositionCommand(h), m_position(v)
    {
    }

    SetPosition²MCommand::SetPosition²MCommand(const SetPosition²MCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }
    
    SetPosition²MCommand::~SetPosition²MCommand()
    {
    }

    PostCPtr    SetPosition²MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition²MCommand(*this, h);
    }
    
    void SetPosition²MCommand::init_meta()
    {
        auto w = writer<SetPosition²MCommand>();
        w.description("Set Position Command");
        w.property("x", &SetPosition²MCommand::x).tag(kTag_Log);
        w.property("y", &SetPosition²MCommand::y).tag(kTag_Log);
        w.property("position", &SetPosition²MCommand::m_position).tag(kTag_Save);
    }
}
