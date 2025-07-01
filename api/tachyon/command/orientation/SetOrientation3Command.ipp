////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/orientation/SetOrientation3Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/vector/Quaternion3.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOrientation³Command)

namespace yq::tachyon {
    SetOrientation³Command::SetOrientation³Command(const Header& h, const Quaternion3D& v) : 
        OrientationCommand(h), m_orientation(v)
    {
    }

    SetOrientation³Command::SetOrientation³Command(const Header& h, hpr_k, Radian hdg, Radian pitch, Radian roll) :
        OrientationCommand(h), m_orientation(HPR, hdg, pitch, roll)
    {
    }
    
    SetOrientation³Command::SetOrientation³Command(const SetOrientation³Command& cp, const Header&h) : 
        OrientationCommand(cp, h), m_orientation(cp.m_orientation)
    {
    }

    SetOrientation³Command::~SetOrientation³Command()
    {
    }
    
    PostCPtr    SetOrientation³Command::clone(rebind_k, const Header&h) const 
    {
        return new SetOrientation³Command(*this, h);
    }

    void SetOrientation³Command::init_info()
    {
        auto w = writer<SetOrientation³Command>();
        w.description("Set Orientation Command");
        w.property("w", &SetOrientation³Command::w);
        w.property("x", &SetOrientation³Command::x);
        w.property("y", &SetOrientation³Command::y);
        w.property("z", &SetOrientation³Command::z);
    }
}
