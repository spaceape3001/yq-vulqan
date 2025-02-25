////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/scale/SetScale2.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScale²)

namespace yq::tachyon {
    SetScale²::SetScale²(const Header& h, const Vector2D& v) : 
        ScaleCommand(h), m_scale(v)
    {
    }

    SetScale²::SetScale²(const SetScale²& cp, const Header& h) : 
        ScaleCommand(cp, h), m_scale(cp.m_scale)
    {
    }
    
    SetScale²::~SetScale²()
    {
    }

    PostCPtr    SetScale²::clone(rebind_k, const Header&h) const 
    {
        return new SetScale²(*this, h);
    }
    
    void SetScale²::init_info()
    {
        auto w = writer<SetScale²>();
        w.description("Set Scale Command");
        w.property("x", &SetScale²::x);
        w.property("y", &SetScale²::y);
    }
}
