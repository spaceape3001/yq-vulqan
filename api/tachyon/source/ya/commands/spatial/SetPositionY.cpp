////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetPositionY.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionʸ)

namespace yq::tachyon {
    SetPositionʸ::SetPositionʸ(const Header&h, double y) : 
        SpatialCommand(h), m_y(y)
    {
    }

    SetPositionʸ::SetPositionʸ(const SetPositionʸ& cp, const Header&h) : 
        SpatialCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetPositionʸ::~SetPositionʸ()
    {
    }
    
    PostCPtr    SetPositionʸ::clone(rebind_k, const Header&h) const 
    {
        return new SetPositionʸ(*this, h);
    }

    void SetPositionʸ::init_info()
    {
        auto w = writer<SetPositionʸ>();
        w.description("Set Position Command");
        w.property("y", &SetPositionʸ::y);
    }
}
