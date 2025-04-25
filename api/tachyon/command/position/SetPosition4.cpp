////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/SetPosition4.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition⁴)

namespace yq::tachyon {
    SetPosition⁴::SetPosition⁴(const Header& h, const Vector4D& v) : 
        PositionCommand(h), m_position(v)
    {
    }
    
    SetPosition⁴::SetPosition⁴(const SetPosition⁴& cp, const Header& h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }

    SetPosition⁴::~SetPosition⁴()
    {
    }
    
    PostCPtr    SetPosition⁴::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition⁴(*this, h);
    }

    void SetPosition⁴::init_info()
    {
        auto w = writer<SetPosition⁴>();
        w.description("Set Position Command");
        w.property("w", &SetPosition⁴::w);
        w.property("x", &SetPosition⁴::x);
        w.property("y", &SetPosition⁴::y);
        w.property("z", &SetPosition⁴::z);
    }
}
