////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetOffset3Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOffset³Command)

namespace yq::tachyon {
    SetOffset³Command::SetOffset³Command(const Header& h, const Vector3D& v) : 
        OffsetCommand(h), m_offset(v)
    {
    }
    
    SetOffset³Command::SetOffset³Command(const SetOffset³Command& cp, const Header& h) : 
        OffsetCommand(cp, h), m_offset(cp.m_position)
    {
    }

    SetOffset³Command::~SetOffset³Command()
    {
    }
    
    PostCPtr    SetOffset³Command::clone(rebind_k, const Header&h) const 
    {
        return new SetOffset³Command(*this, h);
    }

    void SetOffset³Command::init_meta()
    {
        auto w = writer<SetOffset³Command>();
        w.description("Set Offset Command");
        w.property("x", &SetOffset³Command::x);
        w.property("y", &SetOffset³Command::y);
        w.property("z", &SetOffset³Command::z);
    }
}
