////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MovePosition2I.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MovePosition2I)

namespace yq::tachyon {
    MovePosition2I::MovePosition2I(TachyonID tid, const Vector2I& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    MovePosition2I::~MovePosition2I()
    {
    }
    
    void MovePosition2I::init_info()
    {
        auto w = writer<MovePosition2I>();
        w.description("Move Position Command");
        w.property("x", &MovePosition2I::x);
        w.property("y", &MovePosition2I::y);
    }
}
