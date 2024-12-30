////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScale³.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScale³)

namespace yq::tachyon {
    SetScale³::SetScale³(TachyonID tid, const Vector3D& v, const Param& p) : 
        SpatialCommand(tid, p), m_scale(v)
    {
    }
    
    SetScale³::~SetScale³()
    {
    }
    
    void SetScale³::init_info()
    {
        auto w = writer<SetScale³>();
        w.description("Set Scale Command");
        w.property("x", &SetScale³::x);
        w.property("y", &SetScale³::y);
        w.property("z", &SetScale³::z);
    }
}
