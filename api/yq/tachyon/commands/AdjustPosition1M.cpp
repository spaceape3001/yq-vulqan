////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AdjustPosition1M.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AdjustPosition1M)

namespace yq::tachyon {
    AdjustPosition1M::AdjustPosition1M(TachyonID tid, const Vector1M& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    AdjustPosition1M::~AdjustPosition1M()
    {
    }
    
    void AdjustPosition1M::init_info()
    {
        auto w = writer<AdjustPosition1M>();
        w.description("Adjust Position Command");
        w.property("x", &AdjustPosition1M::x);
    }
}
