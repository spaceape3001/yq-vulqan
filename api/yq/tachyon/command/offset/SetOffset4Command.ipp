////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetOffset4Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOffset⁴Command)

namespace yq::tachyon {
    SetOffset⁴Command::SetOffset⁴Command(const Header& h, const Vector4D& v) : 
        OffsetCommand(h), m_offset(v)
    {
    }
    
    SetOffset⁴Command::SetOffset⁴Command(const SetOffset⁴Command& cp, const Header& h) : 
        OffsetCommand(cp, h), m_offset(cp.m_position)
    {
    }

    SetOffset⁴Command::~SetOffset⁴Command()
    {
    }
    
    PostCPtr    SetOffset⁴Command::clone(rebind_k, const Header&h) const 
    {
        return new SetOffset⁴Command(*this, h);
    }

    void SetOffset⁴Command::init_meta()
    {
        auto w = writer<SetOffset⁴Command>();
        w.description("Set Offset Command");
        w.property("w", &SetOffset⁴Command::w);
        w.property("x", &SetOffset⁴Command::x);
        w.property("y", &SetOffset⁴Command::y);
        w.property("z", &SetOffset⁴Command::z);
    }
}
