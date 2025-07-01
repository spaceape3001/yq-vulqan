////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/orientation/SetOrientation2Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/vector/Spinor2.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOrientation²Command)

namespace yq::tachyon {
    SetOrientation²Command::SetOrientation²Command(const Header& h, const Spinor2D& v) : 
        OrientationCommand(h), m_orientation(v)
    {
    }

    SetOrientation²Command::SetOrientation²Command(const Header& h, hpr_k, Radian hdg) :
        OrientationCommand(h), m_orientation(CLOCKWISE, hdg)
    {
    }
    
    SetOrientation²Command::SetOrientation²Command(const SetOrientation²Command& cp, const Header&h) : 
        OrientationCommand(cp, h), m_orientation(cp.m_orientation)
    {
    }

    SetOrientation²Command::~SetOrientation²Command()
    {
    }
    
    PostCPtr    SetOrientation²Command::clone(rebind_k, const Header&h) const 
    {
        return new SetOrientation²Command(*this, h);
    }

    void SetOrientation²Command::init_meta()
    {
        auto w = writer<SetOrientation²Command>();
        w.description("Set Orientation Command");
        w.property("a", &SetOrientation²Command::a);
        w.property("xy", &SetOrientation²Command::xy);
    }
}
