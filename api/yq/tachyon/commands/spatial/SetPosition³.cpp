////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition3.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition3)

namespace yq::tachyon {
    SetPosition3::SetPosition3(TachyonID tid, const Vector3D& v, const Param& p) : 
        SpatialCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition3::~SetPosition3()
    {
    }
    
    void SetPosition3::init_info()
    {
        auto w = writer<SetPosition3>();
        w.description("Set Position Command");
        w.property("x", &SetPosition3::x);
        w.property("y", &SetPosition3::y);
        w.property("z", &SetPosition3::z);
    }
}
