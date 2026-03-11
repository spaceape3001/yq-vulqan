////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition3DCommand.hpp"
#include <yq/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition³DCommand)

namespace yq::tachyon {
    SetPosition³DCommand::SetPosition³DCommand(const Header& h, const Vector3D& v) : 
        PositionCommand(h), m_position(v)
    {
    }
    
    SetPosition³DCommand::SetPosition³DCommand(const SetPosition³DCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }

    SetPosition³DCommand::~SetPosition³DCommand()
    {
    }
    
    PostCPtr    SetPosition³DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition³DCommand(*this, h);
    }

    void SetPosition³DCommand::init_meta()
    {
        auto w = writer<SetPosition³DCommand>();
        w.description("Set Position Command");
        w.property("x", &SetPosition³DCommand::x).tag(kTag_Log);
        w.property("y", &SetPosition³DCommand::y).tag(kTag_Log);
        w.property("z", &SetPosition³DCommand::z).tag(kTag_Log);
        w.property("position", &SetPosition³DCommand::m_position).tag(kTag_Save);
    }
}
