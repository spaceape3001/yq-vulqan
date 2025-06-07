////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/orientation/RotateBy3Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/vector/Vector3.hxx>
#include <yq/vector/Quaternion3.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RotateBy³Command)

namespace yq::tachyon {
    RotateBy³Command::RotateBy³Command(const Header& h, const Quaternion3D&δ) : 
        OrientationCommand(h), m_δ(δ)
    {
    }
    
    RotateBy³Command::RotateBy³Command(const Header& h, const unit::Radian3D&δ) :
        OrientationCommand(h), m_δ(CCW, δ)
    {
    }
    
    RotateBy³Command::RotateBy³Command(const RotateBy³Command& cp, const Header& h) : 
        OrientationCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    RotateBy³Command::~RotateBy³Command()
    {
    }
    
    PostCPtr    RotateBy³Command::clone(rebind_k, const Header& h) const 
    {
        return new RotateBy³Command(*this, h);
    }

    void RotateBy³Command::init_info()
    {
        auto w = writer<RotateBy³Command>();
        w.description("Position RotateBy Command in 3D");
        w.property("δw", &RotateBy³Command::δw);
        w.property("δx", &RotateBy³Command::δx);
        w.property("δy", &RotateBy³Command::δy);
        w.property("δz", &RotateBy³Command::δz);
    }
}
