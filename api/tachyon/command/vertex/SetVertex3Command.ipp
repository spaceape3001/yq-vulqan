////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetVertex3Command.hpp"
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetVertex³Command)

namespace yq::tachyon {

    SetVertex³Command::SetVertex³Command(const Header&h, size_t v, const Vertex³&data) : 
        VertexCommand(h), m_data(data), m_vertex(v)
    {
    }

    SetVertex³Command::SetVertex³Command(const SetVertex³Command& cp, const Header& h) : 
        VertexCommand(cp, h), m_data(cp.m_data), m_vertex(cp.m_vertex)
    {
    }
    
    SetVertex³Command::~SetVertex³Command()
    {
    }

    PostCPtr    SetVertex³Command::clone(rebind_k, const Header&h) const 
    {
        return new SetVertex³Command(*this, h);
    }
    
    void        SetVertex³Command::set_color(const RGBA4F&v)
    {
        m_data.color = v;
    }

    void        SetVertex³Command::set_data(const Vertex³&v)
    {
        m_data = v;
    }

    void        SetVertex³Command::set_normal(const Vector3F&v)
    {
        m_data.normal = v;
    }

    void        SetVertex³Command::set_point(const Vector3D&v)
    {
        m_data.point = v;
    }

    void        SetVertex³Command::set_uv(const UV2F&v)
    {
        m_data.uv = v;
    }

    void        SetVertex³Command::set_vertex(size_t n)
    {
        m_vertex = n;
    }

    ////////////////////////////////////////////////////////////////////////////

    void SetVertex³Command::init_info()
    {
        auto w = writer<SetVertex³Command>();
        w.description("Set Vertex 3D Command");

        w.property("vertex", &SetVertex³Command::m_vertex).tag(kTag_Save).tag(kTag_Log);
        w.property("data", &SetVertex³Command::m_data).tag(kTag_Save);
        
        w.property("color", &SetVertex³Command::color).setter(&SetVertex³Command::set_color);
        w.property("red", &SetVertex³Command::red).tag(kTag_Log);
        w.property("green", &SetVertex³Command::green).tag(kTag_Log);
        w.property("blue", &SetVertex³Command::blue).tag(kTag_Log);
        w.property("alpha", &SetVertex³Command::alpha).tag(kTag_Log);
        
        w.property("point", &SetVertex³Command::point).setter(&SetVertex³Command::set_point);
        w.property("x", &SetVertex³Command::x).tag(kTag_Log);
        w.property("y", &SetVertex³Command::y).tag(kTag_Log);
        w.property("z", &SetVertex³Command::z).tag(kTag_Log);
        
        w.property("normal", &SetVertex³Command::normal).setter(&SetVertex³Command::set_normal);
        w.property("nx", &SetVertex³Command::nx).tag(kTag_Log);
        w.property("ny", &SetVertex³Command::ny).tag(kTag_Log);
        w.property("nz", &SetVertex³Command::nz).tag(kTag_Log);
        
        w.property("uv", &SetVertex³Command::uv).setter(&SetVertex³Command::set_uv);
        w.property("u", &SetVertex³Command::u).tag(kTag_Log);
        w.property("v", &SetVertex³Command::v).tag(kTag_Log);
    }
}
