////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/orientation/SetOrientation2.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/vector/Spinor2.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOrientation²)

namespace yq::tachyon {
    SetOrientation²::SetOrientation²(const Header& h, const Spinor2D& v) : 
        OrientationCommand(h), m_orientation(v)
    {
    }

    SetOrientation²::SetOrientation²(const Header& h, hpr_k, Radian hdg) :
        OrientationCommand(h), m_orientation(CLOCKWISE, hdg)
    {
    }
    
    SetOrientation²::SetOrientation²(const SetOrientation²& cp, const Header&h) : 
        OrientationCommand(cp, h), m_orientation(cp.m_orientation)
    {
    }

    SetOrientation²::~SetOrientation²()
    {
    }
    
    PostCPtr    SetOrientation²::clone(rebind_k, const Header&h) const 
    {
        return new SetOrientation²(*this, h);
    }

    void SetOrientation²::init_info()
    {
        auto w = writer<SetOrientation²>();
        w.description("Set Orientation Command");
        w.property("a", &SetOrientation²::a);
        w.property("xy", &SetOrientation²::xy);
    }
}
