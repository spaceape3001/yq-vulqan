////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition2CMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition²CMCommand)

namespace yq::tachyon {
    SetPosition²CMCommand::SetPosition²CMCommand(const Header& h, const Centimeter2D& v) : 
        PositionCommand(h), m_position(v)
    {
    }

    SetPosition²CMCommand::SetPosition²CMCommand(const SetPosition²CMCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }
    
    SetPosition²CMCommand::~SetPosition²CMCommand()
    {
    }

    PostCPtr    SetPosition²CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition²CMCommand(*this, h);
    }
    
    void SetPosition²CMCommand::init_meta()
    {
        auto w = writer<SetPosition²CMCommand>();
        w.description("Set Position Command");
        w.property("x", &SetPosition²CMCommand::x).tag(kTag_Log);
        w.property("y", &SetPosition²CMCommand::y).tag(kTag_Log);
        w.property("position", &SetPosition²CMCommand::m_position).tag(kTag_Save);
    }
}
