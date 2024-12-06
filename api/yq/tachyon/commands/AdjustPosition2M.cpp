////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AdjustPosition2M.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AdjustPosition2M)

namespace yq::tachyon {
    AdjustPosition2M::AdjustPosition2M(TachyonID tid, const Vector2M& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    AdjustPosition2M::~AdjustPosition2M()
    {
    }
    
    void AdjustPosition2M::init_info()
    {
        auto w = writer<AdjustPosition2M>();
        w.description("Adjust Position Command");
        w.property("x", &AdjustPosition2M::x);
        w.property("y", &AdjustPosition2M::y);
    }
}
