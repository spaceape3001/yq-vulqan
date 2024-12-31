////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RotateBy3.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/vector/Vector3.hxx>
#include <yq/vector/Quaternion3.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RotateBy3)

namespace yq::tachyon {
    RotateBy3::RotateBy3(TachyonID tid, const Quaternion3D&δ, const Param& p) : 
        SpatialCommand(tid, p), m_δ(δ)
    {
    }
    
    RotateBy3::RotateBy3(TachyonID tid, const unit::Radian3D&δ, const Param& p) :
        SpatialCommand(tid, p), m_δ(CCW, δ)
    {
    }
    
    RotateBy3::~RotateBy3()
    {
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
