////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/SetVertexPosition3Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetVertexPosition³Command)

namespace yq::tachyon {
    SetVertexPosition³Command::SetVertexPosition³Command(const Header& h, unsigned v, const Vector3D& p) : 
        PositionCommand(h), m_position(p), m_vertex(v)
    {
    }
    
    SetVertexPosition³Command::SetVertexPosition³Command(const SetVertexPosition³Command& cp, const Header& h) : 
        PositionCommand(cp, h), m_position(cp.m_position), m_vertex(cp.m_vertex)
    {
    }

    SetVertexPosition³Command::~SetVertexPosition³Command()
    {
    }
    
    PostCPtr    SetVertexPosition³Command::clone(rebind_k, const Header&h) const 
    {
        return new SetVertexPosition³Command(*this, h);
    }

    void SetVertexPosition³Command::init_info()
    {
        auto w = writer<SetVertexPosition³Command>();
        w.description("Set Vertex Position Command");
        w.property("x", &SetVertexPosition³Command::x);
        w.property("y", &SetVertexPosition³Command::y);
        w.property("z", &SetVertexPosition³Command::z);
    }
}
