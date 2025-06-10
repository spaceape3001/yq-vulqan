////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetVertexNormal3Command.hpp"
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetVertexNormal³Command)

namespace yq::tachyon {

    SetVertexNormal³Command::SetVertexNormal³Command(const Header&h, size_t v, const Vector3F&coord) : 
        VertexCommand(h), m_normal(coord), m_vertex(v)
    {
    }

    SetVertexNormal³Command::SetVertexNormal³Command(const SetVertexNormal³Command& cp, const Header& h) : 
        VertexCommand(cp, h), m_normal(cp.m_normal), m_vertex(cp.m_vertex)
    {
    }
    
    SetVertexNormal³Command::~SetVertexNormal³Command()
    {
    }

    PostCPtr    SetVertexNormal³Command::clone(rebind_k, const Header&h) const 
    {
        return new SetVertexNormal³Command(*this, h);
    }
    
    void        SetVertexNormal³Command::set_normal(const Vector3F&v)
    {
        m_normal    = v;
    }

    void        SetVertexNormal³Command::set_vertex(size_t n)
    {
        m_vertex = n;
    }

    ////////////////////////////////////////////////////////////////////////////

    void SetVertexNormal³Command::init_info()
    {
        auto w = writer<SetVertexNormal³Command>();
        w.description("Set Vertex 3D Normal Command");
        w.property("normal", &SetVertexNormal³Command::m_normal).tag(kTag_Save);
        w.property("vertex", &SetVertexNormal³Command::m_vertex).tag(kTag_Save).tag(kTag_Log);
        w.property("nx", &SetVertexNormal³Command::nx).tag(kTag_Log);
        w.property("ny", &SetVertexNormal³Command::ny).tag(kTag_Log);
        w.property("nz", &SetVertexNormal³Command::nz).tag(kTag_Log);
    }
}
