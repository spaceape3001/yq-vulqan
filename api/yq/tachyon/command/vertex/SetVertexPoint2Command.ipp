////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetVertexPoint2Command.hpp"
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetVertexPoint²Command)

namespace yq::tachyon {

    SetVertexPoint²Command::SetVertexPoint²Command(const Header&h, size_t v, const Vector2D&coord) : 
        VertexCommand(h), m_point(coord), m_vertex(v)
    {
    }

    SetVertexPoint²Command::SetVertexPoint²Command(const SetVertexPoint²Command& cp, const Header& h) : 
        VertexCommand(cp, h), m_point(cp.m_point), m_vertex(cp.m_vertex)
    {
    }
    
    SetVertexPoint²Command::~SetVertexPoint²Command()
    {
    }

    PostCPtr    SetVertexPoint²Command::clone(rebind_k, const Header&h) const 
    {
        return new SetVertexPoint²Command(*this, h);
    }
    
    void        SetVertexPoint²Command::set_point(const Vector2D&v)
    {
        m_point    = v;
    }

    void        SetVertexPoint²Command::set_vertex(size_t n)
    {
        m_vertex = n;
    }

    ////////////////////////////////////////////////////////////////////////////

    void SetVertexPoint²Command::init_meta()
    {
        auto w = writer<SetVertexPoint²Command>();
        w.description("Set Vertex 2D Point Command");
        w.property("point", &SetVertexPoint²Command::m_point).tag(kTag_Save);
        w.property("vertex", &SetVertexPoint²Command::m_vertex).tag(kTag_Save).tag(kTag_Log);
        w.property("x", &SetVertexPoint²Command::x).tag(kTag_Log);
        w.property("y", &SetVertexPoint²Command::y).tag(kTag_Log);
    }
}
