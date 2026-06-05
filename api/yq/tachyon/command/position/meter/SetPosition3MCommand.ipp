////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition3MCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition³MCommand)

namespace yq::tachyon {
    SetPosition³MCommand::SetPosition³MCommand(const Header& h, const Meter3D& v) : 
        PositionCommand(h), m_position(v)
    {
    }
    
    SetPosition³MCommand::SetPosition³MCommand(const SetPosition³MCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }

    SetPosition³MCommand::~SetPosition³MCommand()
    {
    }
    
    PostCPtr    SetPosition³MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition³MCommand(*this, h);
    }

    void SetPosition³MCommand::init_meta()
    {
        auto w = writer<SetPosition³MCommand>();
        w.description("Set Position Command");
        w.property("x", &SetPosition³MCommand::x).tag(kTag_Log);
        w.property("y", &SetPosition³MCommand::y).tag(kTag_Log);
        w.property("z", &SetPosition³MCommand::z).tag(kTag_Log);
        w.property("position", &SetPosition³MCommand::m_position).tag(kTag_Save);
    }
}
