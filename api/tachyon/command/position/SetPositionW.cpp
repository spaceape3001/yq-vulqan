////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/SetPositionW.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionʷ)

namespace yq::tachyon {
    SetPositionʷ::SetPositionʷ(const Header&h, double w) : 
        PositionCommand(h), m_w(w)
    {
    }
    
    SetPositionʷ::SetPositionʷ(const SetPositionʷ& cp, const Header&h) : 
        PositionCommand(cp, h), m_w(cp.m_w)
    {
    }

    SetPositionʷ::~SetPositionʷ()
    {
    }

    PostCPtr    SetPositionʷ::clone(rebind_k, const Header& h) const
    {
        return new SetPositionʷ(*this, h);
    }
    
    void SetPositionʷ::init_info()
    {
        auto w = writer<SetPositionʷ>();
        w.description("Set Position Command");
        w.property("w", &SetPositionʷ::m_w);
    }
}
