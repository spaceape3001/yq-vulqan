////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition4MCommand.hpp"

#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition⁴MCommand)

namespace yq::tachyon {
    SetPosition⁴MCommand::SetPosition⁴MCommand(const Header& h, const Meter4D& v) : 
        PositionCommand(h), m_position(v)
    {
    }
    
    SetPosition⁴MCommand::SetPosition⁴MCommand(const SetPosition⁴MCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }

    SetPosition⁴MCommand::~SetPosition⁴MCommand()
    {
    }
    
    PostCPtr    SetPosition⁴MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition⁴MCommand(*this, h);
    }

    void SetPosition⁴MCommand::init_meta()
    {
        auto w = writer<SetPosition⁴MCommand>();
        w.description("Set Position Command");
        w.property("w", &SetPosition⁴MCommand::w).tag(kTag_Log);
        w.property("x", &SetPosition⁴MCommand::x).tag(kTag_Log);
        w.property("y", &SetPosition⁴MCommand::y).tag(kTag_Log);
        w.property("z", &SetPosition⁴MCommand::z).tag(kTag_Log);
        w.property("position", &SetPosition⁴MCommand::m_position).tag(kTag_Save);
    }
}
