////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition4DCommand.hpp"
#include <yq/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition⁴DCommand)

namespace yq::tachyon {
    SetPosition⁴DCommand::SetPosition⁴DCommand(const Header& h, const Vector4D& v) : 
        PositionCommand(h), m_position(v)
    {
    }
    
    SetPosition⁴DCommand::SetPosition⁴DCommand(const SetPosition⁴DCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }

    SetPosition⁴DCommand::~SetPosition⁴DCommand()
    {
    }
    
    PostCPtr    SetPosition⁴DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition⁴DCommand(*this, h);
    }

    void SetPosition⁴DCommand::init_meta()
    {
        auto w = writer<SetPosition⁴DCommand>();
        w.description("Set Position Command");
        w.property("w", &SetPosition⁴DCommand::w).tag(kTag_Log);
        w.property("x", &SetPosition⁴DCommand::x).tag(kTag_Log);
        w.property("y", &SetPosition⁴DCommand::y).tag(kTag_Log);
        w.property("z", &SetPosition⁴DCommand::z).tag(kTag_Log);
        w.property("position", &SetPosition⁴DCommand::m_position).tag(kTag_Save);
    }
}
