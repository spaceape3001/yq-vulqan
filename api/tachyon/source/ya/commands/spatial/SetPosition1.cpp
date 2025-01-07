////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetPosition1.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition¹)

namespace yq::tachyon {
    SetPosition¹::SetPosition¹(const Header&h, const Vector1D& v) : 
        SpatialCommand(h), m_position(v)
    {
    }
    
    SetPosition¹::SetPosition¹(const SetPosition¹& cp, const Header&h) : 
        SpatialCommand(cp, h), m_position(cp.m_position)
    {
    }

    SetPosition¹::~SetPosition¹()
    {
    }

    PostCPtr    SetPosition¹::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition¹(*this, h);
    }
    
    void SetPosition¹::init_info()
    {
        auto w = writer<SetPosition¹>();
        w.description("Set Position Command");
        w.property("x", &SetPosition¹::x);
    }
}
