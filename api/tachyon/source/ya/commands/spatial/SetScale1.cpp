////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetScale1.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScale¹)

namespace yq::tachyon {
    SetScale¹::SetScale¹(const Header& h, const Vector1D& v) : 
        SpatialCommand(h), m_scale(v)
    {
    }
    
    SetScale¹::SetScale¹(const SetScale¹& cp, const Header& h) : 
        SpatialCommand(cp, h), m_scale(cp.m_scale)
    {
    }

    SetScale¹::~SetScale¹()
    {
    }
    
    PostCPtr    SetScale¹::clone(rebind_k, const Header&h) const 
    {
        return new SetScale¹(*this, h);
    }

    void SetScale¹::init_info()
    {
        auto w = writer<SetScale¹>();
        w.description("Set Scale Command");
        w.property("x", &SetScale¹::x);
    }
}
