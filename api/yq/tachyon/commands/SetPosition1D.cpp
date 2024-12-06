////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition1D.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition1D)

namespace yq::tachyon {
    SetPosition1D::SetPosition1D(TachyonID tid, const Vector1D& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition1D::~SetPosition1D()
    {
    }
    
    void SetPosition1D::init_info()
    {
        auto w = writer<SetPosition1D>();
        w.description("Set Position Command");
        w.property("x", &SetPosition1D::x);
    }
}
