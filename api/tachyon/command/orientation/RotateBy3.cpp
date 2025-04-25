////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/orientation/RotateBy3.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/vector/Vector3.hxx>
#include <yq/vector/Quaternion3.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RotateBy³)

namespace yq::tachyon {
    RotateBy³::RotateBy³(const Header& h, const Quaternion3D&δ) : 
        OrientationCommand(h), m_δ(δ)
    {
    }
    
    RotateBy³::RotateBy³(const Header& h, const unit::Radian3D&δ) :
        OrientationCommand(h), m_δ(CCW, δ)
    {
    }
    
    RotateBy³::RotateBy³(const RotateBy³& cp, const Header& h) : 
        OrientationCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    RotateBy³::~RotateBy³()
    {
    }
    
    PostCPtr    RotateBy³::clone(rebind_k, const Header& h) const 
    {
        return new RotateBy³(*this, h);
    }

    void RotateBy³::init_info()
    {
        auto w = writer<RotateBy³>();
        w.description("Position RotateBy Command in 3D");
        w.property("δw", &RotateBy³::δw);
        w.property("δx", &RotateBy³::δx);
        w.property("δy", &RotateBy³::δy);
        w.property("δz", &RotateBy³::δz);
    }
}
