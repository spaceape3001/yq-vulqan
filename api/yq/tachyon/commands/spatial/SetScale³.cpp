////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScale3.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScale3)

namespace yq::tachyon {
    SetScale3::SetScale3(TachyonID tid, const Vector3D& v, const Param& p) : 
        SpatialCommand(tid, p), m_scale(v)
    {
    }
    
    SetScale3::~SetScale3()
    {
    }
    
    void SetScale3::init_info()
    {
        auto w = writer<SetScale3>();
        w.description("Set Scale Command");
        w.property("x", &SetScale3::x);
        w.property("y", &SetScale3::y);
        w.property("z", &SetScale3::z);
    }
}
