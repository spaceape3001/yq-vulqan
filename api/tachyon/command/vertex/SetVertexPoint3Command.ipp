////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetVertexPoint3Command.hpp"
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetVertexPoint³Command)

namespace yq::tachyon {

    SetVertexPoint³Command::SetVertexPoint³Command(const Header&h, size_t v, const Vector3D&coord) : 
        VertexCommand(h), m_point(coord), m_vertex(v)
    {
    }

    SetVertexPoint³Command::SetVertexPoint³Command(const SetVertexPoint³Command& cp, const Header& h) : 
        VertexCommand(cp, h), m_point(cp.m_point), m_vertex(cp.m_vertex)
    {
    }
    
    SetVertexPoint³Command::~SetVertexPoint³Command()
    {
    }

    PostCPtr    SetVertexPoint³Command::clone(rebind_k, const Header&h) const 
    {
        return new SetVertexPoint³Command(*this, h);
    }
    
    void        SetVertexPoint³Command::set_point(const Vector3D&v)
    {
        m_point    = v;
    }

    void        SetVertexPoint³Command::set_vertex(size_t n)
    {
        m_vertex = n;
    }

    ////////////////////////////////////////////////////////////////////////////

    void SetVertexPoint³Command::init_info()
    {
        auto w = writer<SetVertexPoint³Command>();
        w.description("Set Vertex 3D Point Command");
        w.property("point", &SetVertexPoint³Command::m_point).tag(kTag_Save);
        w.property("vertex", &SetVertexPoint³Command::m_vertex).tag(kTag_Save).tag(kTag_Log);
        w.property("x", &SetVertexPoint³Command::x).tag(kTag_Log);
        w.property("y", &SetVertexPoint³Command::y).tag(kTag_Log);
        w.property("z", &SetVertexPoint³Command::z).tag(kTag_Log);
    }
}
