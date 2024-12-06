////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AdjustPosition3D.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AdjustPosition3D)

namespace yq::tachyon {
    AdjustPosition3D::AdjustPosition3D(TachyonID tid, const Vector3D& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    AdjustPosition3D::~AdjustPosition3D()
    {
    }
    
    void AdjustPosition3D::init_info()
    {
        auto w = writer<AdjustPosition3D>();
        w.description("Adjust Position Command");
        w.property("x", &AdjustPosition3D::x);
        w.property("y", &AdjustPosition3D::y);
        w.property("z", &AdjustPosition3D::z);
    }
}
