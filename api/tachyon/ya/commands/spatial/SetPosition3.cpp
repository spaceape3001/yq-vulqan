////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetPosition3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition³)

namespace yq::tachyon {
    SetPosition³::SetPosition³(const Header& h, const Vector3D& v) : 
        SpatialCommand(h), m_position(v)
    {
    }
    
    SetPosition³::SetPosition³(const SetPosition³& cp, const Header& h) : 
        SpatialCommand(cp, h), m_position(cp.m_position)
    {
    }

    SetPosition³::~SetPosition³()
    {
    }
    
    PostCPtr    SetPosition³::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition³(*this, h);
    }

    void SetPosition³::init_info()
    {
        auto w = writer<SetPosition³>();
        w.description("Set Position Command");
        w.property("x", &SetPosition³::x);
        w.property("y", &SetPosition³::y);
        w.property("z", &SetPosition³::z);
    }
}
