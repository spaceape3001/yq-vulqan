////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition4CMCommand.hpp"

#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition⁴CMCommand)

namespace yq::tachyon {
    SetPosition⁴CMCommand::SetPosition⁴CMCommand(const Header& h, const Centimeter4D& v) : 
        PositionCommand(h), m_position(v)
    {
    }
    
    SetPosition⁴CMCommand::SetPosition⁴CMCommand(const SetPosition⁴CMCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }

    SetPosition⁴CMCommand::~SetPosition⁴CMCommand()
    {
    }
    
    PostCPtr    SetPosition⁴CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition⁴CMCommand(*this, h);
    }

    void SetPosition⁴CMCommand::init_meta()
    {
        auto w = writer<SetPosition⁴CMCommand>();
        w.description("Set Position Command");
        w.property("w", &SetPosition⁴CMCommand::w).tag(kTag_Log);
        w.property("x", &SetPosition⁴CMCommand::x).tag(kTag_Log);
        w.property("y", &SetPosition⁴CMCommand::y).tag(kTag_Log);
        w.property("z", &SetPosition⁴CMCommand::z).tag(kTag_Log);
        w.property("position", &SetPosition⁴CMCommand::m_position).tag(kTag_Save);
    }
}
