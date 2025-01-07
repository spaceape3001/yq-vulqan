////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/RotateBy3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/vector/Vector3.hxx>
#include <yq/vector/Quaternion3.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RotateBy3)

namespace yq::tachyon {
    RotateBy3::RotateBy3(const Header& h, const Quaternion3D&δ) : 
        SpatialCommand(h), m_δ(δ)
    {
    }
    
    RotateBy3::RotateBy3(const Header& h, const unit::Radian3D&δ) :
        SpatialCommand(h), m_δ(CCW, δ)
    {
    }
    
    RotateBy3::RotateBy3(const RotateBy3& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    RotateBy3::~RotateBy3()
    {
    }
    
    PostCPtr    RotateBy3::clone(rebind_k, const Header& h) const 
    {
        return new RotateBy3(*this, h);
    }

    void RotateBy3::init_info()
    {
        auto w = writer<RotateBy3>();
        w.description("Position RotateBy Command in 3D");
        w.property("δw", &RotateBy3::δw);
        w.property("δx", &RotateBy3::δx);
        w.property("δy", &RotateBy3::δy);
        w.property("δz", &RotateBy3::δz);
    }
}
