////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AdjustPosition2D.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AdjustPosition2D)

namespace yq::tachyon {
    AdjustPosition2D::AdjustPosition2D(TachyonID tid, const Vector2D& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    AdjustPosition2D::~AdjustPosition2D()
    {
    }
    
    void AdjustPosition2D::init_info()
    {
        auto w = writer<AdjustPosition2D>();
        w.description("Adjust Position Command");
        w.property("x", &AdjustPosition2D::x);
        w.property("y", &AdjustPosition2D::y);
    }
}
