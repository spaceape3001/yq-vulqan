////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetVertexNormal2Command.hpp"
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetVertexNormal²Command)

namespace yq::tachyon {

    SetVertexNormal²Command::SetVertexNormal²Command(const Header&h, size_t v, const Vector2F&coord) : 
        VertexCommand(h), m_normal(coord), m_vertex(v)
    {
    }

    SetVertexNormal²Command::SetVertexNormal²Command(const SetVertexNormal²Command& cp, const Header& h) : 
        VertexCommand(cp, h), m_normal(cp.m_normal), m_vertex(cp.m_vertex)
    {
    }
    
    SetVertexNormal²Command::~SetVertexNormal²Command()
    {
    }

    PostCPtr    SetVertexNormal²Command::clone(rebind_k, const Header&h) const 
    {
        return new SetVertexNormal²Command(*this, h);
    }
    
    void        SetVertexNormal²Command::set_normal(const Vector2F&v)
    {
        m_normal    = v;
    }

    void        SetVertexNormal²Command::set_vertex(size_t n)
    {
        m_vertex = n;
    }

    ////////////////////////////////////////////////////////////////////////////

    void SetVertexNormal²Command::init_info()
    {
        auto w = writer<SetVertexNormal²Command>();
        w.description("Set Vertex 2D Normal Command");
        w.property("normal", &SetVertexNormal²Command::m_normal).tag(kTag_Save);
        w.property("vertex", &SetVertexNormal²Command::m_vertex).tag(kTag_Save).tag(kTag_Log);
        w.property("nx", &SetVertexNormal²Command::nx).tag(kTag_Log);
        w.property("ny", &SetVertexNormal²Command::ny).tag(kTag_Log);
    }
}
