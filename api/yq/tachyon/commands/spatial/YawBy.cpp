////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "YawBy.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::YawBy)

namespace yq::tachyon {
    YawBy::YawBy(TachyonID tid, Radian θ, const Param& p) : 
        SpatialCommand(tid, p), m_θ(θ)
    {
    }
    
    YawBy::~YawBy()
    {
    }
    
    void YawBy::init_info()
    {
        auto w = writer<YawBy>();
        w.description("Yaw By Command");
        w.property("θ", &YawBy::θ);
    }
}
