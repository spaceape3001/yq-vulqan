////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AdjustPosition3M.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AdjustPosition3M)

namespace yq::tachyon {
    AdjustPosition3M::AdjustPosition3M(TachyonID tid, const Vector3M& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    AdjustPosition3M::~AdjustPosition3M()
    {
    }
    
    void AdjustPosition3M::init_info()
    {
        auto w = writer<AdjustPosition3M>();
        w.description("Adjust Position Command");
        w.property("x", &AdjustPosition3M::x);
        w.property("y", &AdjustPosition3M::y);
        w.property("z", &AdjustPosition3M::z);
    }
}
