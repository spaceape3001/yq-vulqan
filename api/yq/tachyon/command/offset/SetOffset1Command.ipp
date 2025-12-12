////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetOffset1Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOffset¹Command)

namespace yq::tachyon {
    SetOffset¹Command::SetOffset¹Command(const Header&h, const Vector1D& v) : 
        OffsetCommand(h), m_offset(v)
    {
    }
    
    SetOffset¹Command::SetOffset¹Command(const SetOffset¹Command& cp, const Header&h) : 
        OffsetCommand(cp, h), m_offset(cp.m_position)
    {
    }

    SetOffset¹Command::~SetOffset¹Command()
    {
    }

    PostCPtr    SetOffset¹Command::clone(rebind_k, const Header&h) const 
    {
        return new SetOffset¹Command(*this, h);
    }
    
    void SetOffset¹Command::init_meta()
    {
        auto w = writer<SetOffset¹Command>();
        w.description("Set Offset Command");
        w.property("x", &SetOffset¹Command::x);
    }
}
