////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition2DCommand.hpp"
#include <yq/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition²DCommand)

namespace yq::tachyon {
    SetPosition²DCommand::SetPosition²DCommand(const Header& h, const Vector2D& v) : 
        PositionCommand(h), m_position(v)
    {
    }

    SetPosition²DCommand::SetPosition²DCommand(const SetPosition²DCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }
    
    SetPosition²DCommand::~SetPosition²DCommand()
    {
    }

    PostCPtr    SetPosition²DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition²DCommand(*this, h);
    }
    
    void SetPosition²DCommand::init_meta()
    {
        auto w = writer<SetPosition²DCommand>();
        w.description("Set Position Command");
        w.property("x", &SetPosition²DCommand::x).tag(kTag_Log);
        w.property("y", &SetPosition²DCommand::y).tag(kTag_Log);
        w.property("position", &SetPosition²DCommand::m_position).tag(kTag_Save);
    }
}
