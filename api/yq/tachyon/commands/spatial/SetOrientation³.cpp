////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetOrientation³.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/MKS.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOrientation³)

namespace yq::tachyon {
    SetOrientation³::SetOrientation³(TachyonID tid, const Quaternion3D& v, const Param& p) : 
        SpatialCommand(tid, p), m_orientation(v)
    {
    }

    SetOrientation³::SetOrientation³(TachyonID tid, hpr_k, Radian hdg, Radian pitch, Radian roll, const Param& p) :
        SpatialCommand(tid, p), m_orientation(HPR, hdg, pitch, roll)
    {
    }
    
    SetOrientation³::~SetOrientation³()
    {
    }
    
    void SetOrientation³::init_info()
    {
        auto w = writer<SetOrientation³>();
        w.description("Set Position Command");
        w.property("w", &SetOrientation³::w);
        w.property("x", &SetOrientation³::x);
        w.property("y", &SetOrientation³::y);
        w.property("z", &SetOrientation³::z);
    }
}
