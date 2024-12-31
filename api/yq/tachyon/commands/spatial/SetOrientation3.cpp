////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetOrientation3.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/MKS.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOrientation3)

namespace yq::tachyon {
    SetOrientation3::SetOrientation3(TachyonID tid, const Quaternion3D& v, const Param& p) : 
        SpatialCommand(tid, p), m_orientation(v)
    {
    }

    SetOrientation3::SetOrientation3(TachyonID tid, hpr_k, Radian hdg, Radian pitch, Radian roll, const Param& p) :
        SpatialCommand(tid, p), m_orientation(HPR, hdg, pitch, roll)
    {
    }
    
    SetOrientation3::~SetOrientation3()
    {
    }
    
    void SetOrientation3::init_info()
    {
        auto w = writer<SetOrientation3>();
        w.description("Set Position Command");
        w.property("w", &SetOrientation3::w);
        w.property("x", &SetOrientation3::x);
        w.property("y", &SetOrientation3::y);
        w.property("z", &SetOrientation3::z);
    }
}
