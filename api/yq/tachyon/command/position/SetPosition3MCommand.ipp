////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition3MCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition3MCommand)

namespace yq::tachyon {
    SetPosition3MCommand::SetPosition3MCommand(const Header& h, const Meter3D& v) : 
        PositionCommand(h), m_position(v)
    {
    }
    
    SetPosition3MCommand::SetPosition3MCommand(const SetPosition3MCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }

    SetPosition3MCommand::~SetPosition3MCommand()
    {
    }
    
    PostCPtr    SetPosition3MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition3MCommand(*this, h);
    }

    void SetPosition3MCommand::init_meta()
    {
        auto w = writer<SetPosition3MCommand>();
        w.description("Set Position Command");
        w.property("x", &SetPosition3MCommand::x).tag(kTag_Log);
        w.property("y", &SetPosition3MCommand::y).tag(kTag_Log);
        w.property("z", &SetPosition3MCommand::z).tag(kTag_Log);
        w.property("position", &SetPosition3MCommand::m_position).tag(kTag_Save);
    }
}
