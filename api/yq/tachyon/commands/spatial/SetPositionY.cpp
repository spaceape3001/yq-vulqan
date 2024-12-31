////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionY.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionʸ)

namespace yq::tachyon {
    SetPositionʸ::SetPositionʸ(TachyonID tid, double y, const Param& p) : 
        SpatialCommand(tid, p), m_y(y)
    {
    }
    
    SetPositionʸ::~SetPositionʸ()
    {
    }
    
    void SetPositionʸ::init_info()
    {
        auto w = writer<SetPositionʸ>();
        w.description("Set Position Command");
        w.property("y", &SetPositionʸ::y);
    }
}
