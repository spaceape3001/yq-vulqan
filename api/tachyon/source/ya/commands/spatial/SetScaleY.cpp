////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetScaleY.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScaleʸ)

namespace yq::tachyon {
    SetScaleʸ::SetScaleʸ(const Header& h, double y) : 
        SpatialCommand(h), m_y(y)
    {
    }
    
    SetScaleʸ::SetScaleʸ(const SetScaleʸ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_y(cp.m_y)
    {
    }

    SetScaleʸ::~SetScaleʸ()
    {
    }

    PostCPtr    SetScaleʸ::clone(rebind_k, const Header&h) const 
    {
        return new SetScaleʸ(*this, h);
    }
    
    void SetScaleʸ::init_info()
    {
        auto w = writer<SetScaleʸ>();
        w.description("Set Scale Command");
        w.property("y", &SetScaleʸ::y);
    }
}
