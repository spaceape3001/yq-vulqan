////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition2Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition²Command)

namespace yq::tachyon {
    SetPosition²Command::SetPosition²Command(const Header& h, const Vector2D& v) : 
        PositionCommand(h), m_position(v)
    {
    }

    SetPosition²Command::SetPosition²Command(const SetPosition²Command& cp, const Header& h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }
    
    SetPosition²Command::~SetPosition²Command()
    {
    }

    PostCPtr    SetPosition²Command::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition²Command(*this, h);
    }
    
    void SetPosition²Command::init_meta()
    {
        auto w = writer<SetPosition²Command>();
        w.description("Set Position Command");
        w.property("x", &SetPosition²Command::x);
        w.property("y", &SetPosition²Command::y);
    }
}
