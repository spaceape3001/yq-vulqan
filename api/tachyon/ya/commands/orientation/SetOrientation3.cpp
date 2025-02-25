////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetOrientation3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/vector/Quaternion3.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOrientation³)

namespace yq::tachyon {
    SetOrientation³::SetOrientation³(const Header& h, const Quaternion3D& v) : 
        SpatialCommand(h), m_orientation(v)
    {
    }

    SetOrientation³::SetOrientation³(const Header& h, hpr_k, Radian hdg, Radian pitch, Radian roll) :
        SpatialCommand(h), m_orientation(HPR, hdg, pitch, roll)
    {
    }
    
    SetOrientation³::SetOrientation³(const SetOrientation³& cp, const Header&h) : 
        SpatialCommand(cp, h), m_orientation(cp.m_orientation)
    {
    }

    SetOrientation³::~SetOrientation³()
    {
    }
    
    PostCPtr    SetOrientation³::clone(rebind_k, const Header&h) const 
    {
        return new SetOrientation³(*this, h);
    }

    void SetOrientation³::init_info()
    {
        auto w = writer<SetOrientation³>();
        w.description("Set Position Command");
        w.property("w", &SetOrientation³::w);
        w.property("x", &SetOrientation³::x);
        w.property("y", &SetOrientation³::y);
        w.property("z", &SetOrientation³::z);
    }
}
