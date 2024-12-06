////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AdjustPosition4D.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AdjustPosition4D)

namespace yq::tachyon {
    AdjustPosition4D::AdjustPosition4D(TachyonID tid, const Vector4D& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    AdjustPosition4D::~AdjustPosition4D()
    {
    }
    
    void AdjustPosition4D::init_info()
    {
        auto w = writer<AdjustPosition4D>();
        w.description("Adjust Position Command");
        w.property("x", &AdjustPosition4D::x);
        w.property("y", &AdjustPosition4D::y);
        w.property("z", &AdjustPosition4D::z);
        w.property("w", &AdjustPosition4D::w);
    }
}
