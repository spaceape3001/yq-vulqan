////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/position/SetPosition2.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition²)

namespace yq::tachyon {
    SetPosition²::SetPosition²(const Header& h, const Vector2D& v) : 
        PositionCommand(h), m_position(v)
    {
    }

    SetPosition²::SetPosition²(const SetPosition²& cp, const Header& h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }
    
    SetPosition²::~SetPosition²()
    {
    }

    PostCPtr    SetPosition²::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition²(*this, h);
    }
    
    void SetPosition²::init_info()
    {
        auto w = writer<SetPosition²>();
        w.description("Set Position Command");
        w.property("x", &SetPosition²::x);
        w.property("y", &SetPosition²::y);
    }
}
