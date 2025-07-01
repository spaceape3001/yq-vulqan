////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/SetPosition3Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition³Command)

namespace yq::tachyon {
    SetPosition³Command::SetPosition³Command(const Header& h, const Vector3D& v) : 
        PositionCommand(h), m_position(v)
    {
    }
    
    SetPosition³Command::SetPosition³Command(const SetPosition³Command& cp, const Header& h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }

    SetPosition³Command::~SetPosition³Command()
    {
    }
    
    PostCPtr    SetPosition³Command::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition³Command(*this, h);
    }

    void SetPosition³Command::init_info()
    {
        auto w = writer<SetPosition³Command>();
        w.description("Set Position Command");
        w.property("x", &SetPosition³Command::x);
        w.property("y", &SetPosition³Command::y);
        w.property("z", &SetPosition³Command::z);
    }
}
