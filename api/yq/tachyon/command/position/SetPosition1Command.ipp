////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition1Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition¹Command)

namespace yq::tachyon {
    SetPosition¹Command::SetPosition¹Command(const Header&h, const Vector1D& v) : 
        PositionCommand(h), m_position(v)
    {
    }
    
    SetPosition¹Command::SetPosition¹Command(const SetPosition¹Command& cp, const Header&h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }

    SetPosition¹Command::~SetPosition¹Command()
    {
    }

    PostCPtr    SetPosition¹Command::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition¹Command(*this, h);
    }
    
    void SetPosition¹Command::init_meta()
    {
        auto w = writer<SetPosition¹Command>();
        w.description("Set Position Command");
        w.property("x", &SetPosition¹Command::x);
    }
}
