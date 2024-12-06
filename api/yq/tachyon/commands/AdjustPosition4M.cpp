////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AdjustPosition4M.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AdjustPosition4M)

namespace yq::tachyon {
    AdjustPosition4M::AdjustPosition4M(TachyonID tid, const Vector4M& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    AdjustPosition4M::~AdjustPosition4M()
    {
    }
    
    void AdjustPosition4M::init_info()
    {
        auto w = writer<AdjustPosition4M>();
        w.description("Adjust Position Command");
        w.property("x", &AdjustPosition4M::x);
        w.property("y", &AdjustPosition4M::y);
        w.property("z", &AdjustPosition4M::z);
        w.property("w", &AdjustPosition4M::w);
    }
}
