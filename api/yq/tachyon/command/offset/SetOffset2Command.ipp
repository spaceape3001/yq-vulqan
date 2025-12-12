////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetOffset2Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOffset²Command)

namespace yq::tachyon {
    SetOffset²Command::SetOffset²Command(const Header& h, const Vector2D& v) : 
        OffsetCommand(h), m_offset(v)
    {
    }

    SetOffset²Command::SetOffset²Command(const SetOffset²Command& cp, const Header& h) : 
        OffsetCommand(cp, h), m_offset(cp.m_position)
    {
    }
    
    SetOffset²Command::~SetOffset²Command()
    {
    }

    PostCPtr    SetOffset²Command::clone(rebind_k, const Header&h) const 
    {
        return new SetOffset²Command(*this, h);
    }
    
    void SetOffset²Command::init_meta()
    {
        auto w = writer<SetOffset²Command>();
        w.description("Set Offset Command");
        w.property("x", &SetOffset²Command::x);
        w.property("y", &SetOffset²Command::y);
    }
}
