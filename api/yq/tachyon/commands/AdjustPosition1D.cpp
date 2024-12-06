////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AdjustPosition1D.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AdjustPosition1D)

namespace yq::tachyon {
    AdjustPosition1D::AdjustPosition1D(TachyonID tid, const Vector1D& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    AdjustPosition1D::~AdjustPosition1D()
    {
    }
    
    void AdjustPosition1D::init_info()
    {
        auto w = writer<AdjustPosition1D>();
        w.description("Adjust Position Command");
        w.property("x", &AdjustPosition1D::x);
    }
}
