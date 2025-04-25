////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/SetPositionY.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionʸ)

namespace yq::tachyon {
    SetPositionʸ::SetPositionʸ(const Header&h, double y) : 
        PositionCommand(h), m_y(y)
    {
    }

    SetPositionʸ::SetPositionʸ(const SetPositionʸ& cp, const Header&h) : 
        PositionCommand(cp, h), m_y(cp.m_y)
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
