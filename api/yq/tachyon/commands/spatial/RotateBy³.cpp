////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RotateBy³.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/vector/Vector3.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RotateBy³)

namespace yq::tachyon {
    RotateBy³::RotateBy³(TachyonID tid, const Quaternion3D&δ, const Param& p) : 
        SpatialCommand(tid, p), m_δ(δ)
    {
    }
    
    RotateBy³::RotateBy³(TachyonID tid, const unit::Radian3D&δ, const Param& p) :
        SpatialCommand(tid, p), m_δ(CCW, δ)
    {
    }
    
    RotateBy³::~RotateBy³()
    {
    }
    
    void RotateBy³::init_info()
    {
        auto w = writer<RotateBy³>();
        w.description("Position RotateBy Command in ³D");
        w.property("δw", &RotateBy³::δw);
        w.property("δx", &RotateBy³::δx);
        w.property("δy", &RotateBy³::δy);
        w.property("δz", &RotateBy³::δz);
    }
}
