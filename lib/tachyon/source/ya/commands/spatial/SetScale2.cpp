////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetScale2.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScale2)

namespace yq::tachyon {
    SetScale2::SetScale2(TachyonID tid, const Vector2D& v, const Param& p) : 
        SpatialCommand(tid, p), m_scale(v)
    {
    }
    
    SetScale2::~SetScale2()
    {
    }
    
    void SetScale2::init_info()
    {
        auto w = writer<SetScale2>();
        w.description("Set Scale Command");
        w.property("x", &SetScale2::x);
        w.property("y", &SetScale2::y);
    }
}
