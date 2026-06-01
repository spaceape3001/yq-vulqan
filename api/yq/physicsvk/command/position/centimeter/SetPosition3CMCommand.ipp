////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition3CMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition³CMCommand)

namespace yq::tachyon {
    SetPosition³CMCommand::SetPosition³CMCommand(const Header& h, const Centimeter3D& v) : 
        PositionCommand(h), m_position(v)
    {
    }
    
    SetPosition³CMCommand::SetPosition³CMCommand(const SetPosition³CMCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }

    SetPosition³CMCommand::~SetPosition³CMCommand()
    {
    }
    
    PostCPtr    SetPosition³CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition³CMCommand(*this, h);
    }

    void SetPosition³CMCommand::init_meta()
    {
        auto w = writer<SetPosition³CMCommand>();
        w.description("Set Position Command");
        w.property("x", &SetPosition³CMCommand::x).tag(kTag_Log);
        w.property("y", &SetPosition³CMCommand::y).tag(kTag_Log);
        w.property("z", &SetPosition³CMCommand::z).tag(kTag_Log);
        w.property("position", &SetPosition³CMCommand::m_position).tag(kTag_Save);
    }
}
