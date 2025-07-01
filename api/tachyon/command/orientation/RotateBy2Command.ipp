////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/orientation/RotateBy2Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/vector/Spinor2.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RotateBy²Command)

namespace yq::tachyon {
    RotateBy²Command::RotateBy²Command(const Header& h, const Spinor2D&δ) : 
        OrientationCommand(h), m_δ(δ)
    {
    }
    
    RotateBy²Command::RotateBy²Command(const Header& h, Radian δ) :
        OrientationCommand(h), m_δ(CCW, δ)
    {
    }
    
    RotateBy²Command::RotateBy²Command(const RotateBy²Command& cp, const Header& h) : 
        OrientationCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    RotateBy²Command::~RotateBy²Command()
    {
    }
    
    PostCPtr    RotateBy²Command::clone(rebind_k, const Header& h) const 
    {
        return new RotateBy²Command(*this, h);
    }

    void RotateBy²Command::init_meta()
    {
        auto w = writer<RotateBy²Command>();
        w.description("Position RotateBy Command in 3D");
        w.property("δa", &RotateBy²Command::δa);
        w.property("δxy", &RotateBy²Command::δxy);
    }
}
