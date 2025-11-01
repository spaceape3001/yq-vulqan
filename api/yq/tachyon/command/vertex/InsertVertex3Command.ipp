////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "InsertVertex3Command.hpp"
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::InsertVertex³Command)

namespace yq::tachyon {

    InsertVertex³Command::InsertVertex³Command(const Header&h, size_t v, const Vertex³&data) : 
        VertexCommand(h), m_data(data), m_vertex(v)
    {
    }

    InsertVertex³Command::InsertVertex³Command(const InsertVertex³Command& cp, const Header& h) : 
        VertexCommand(cp, h), m_data(cp.m_data), m_vertex(cp.m_vertex)
    {
    }
    
    InsertVertex³Command::~InsertVertex³Command()
    {
    }

    PostCPtr    InsertVertex³Command::clone(rebind_k, const Header&h) const 
    {
        return new InsertVertex³Command(*this, h);
    }
    
    void        InsertVertex³Command::set_color(const RGBA4F&v)
    {
        m_data.color = v;
    }

    void        InsertVertex³Command::set_data(const Vertex³&v)
    {
        m_data = v;
    }

    void        InsertVertex³Command::set_normal(const Vector3F&v)
    {
        m_data.normal = v;
    }

    void        InsertVertex³Command::set_point(const Vector3D&v)
    {
        m_data.point = v;
    }

    void        InsertVertex³Command::set_uv(const UV2F&v)
    {
        m_data.uv = v;
    }

    void        InsertVertex³Command::set_vertex(size_t n)
    {
        m_vertex = n;
    }

    ////////////////////////////////////////////////////////////////////////////

    void InsertVertex³Command::init_meta()
    {
        auto w = writer<InsertVertex³Command>();
        w.description("Insert Vertex 3D Command");

        w.property("vertex", &InsertVertex³Command::m_vertex).tag(kTag_Save).tag(kTag_Log);
        w.property("data", &InsertVertex³Command::m_data).tag(kTag_Save);
        
        w.property("color", &InsertVertex³Command::color).setter(&InsertVertex³Command::set_color);
        w.property("red", &InsertVertex³Command::red).tag(kTag_Log);
        w.property("green", &InsertVertex³Command::green).tag(kTag_Log);
        w.property("blue", &InsertVertex³Command::blue).tag(kTag_Log);
        w.property("alpha", &InsertVertex³Command::alpha).tag(kTag_Log);
        
        w.property("point", &InsertVertex³Command::point).setter(&InsertVertex³Command::set_point);
        w.property("x", &InsertVertex³Command::x).tag(kTag_Log);
        w.property("y", &InsertVertex³Command::y).tag(kTag_Log);
        w.property("z", &InsertVertex³Command::z).tag(kTag_Log);
        
        w.property("normal", &InsertVertex³Command::normal).setter(&InsertVertex³Command::set_normal);
        w.property("nx", &InsertVertex³Command::nx).tag(kTag_Log);
        w.property("ny", &InsertVertex³Command::ny).tag(kTag_Log);
        w.property("nz", &InsertVertex³Command::nz).tag(kTag_Log);
        
        w.property("uv", &InsertVertex³Command::uv).setter(&InsertVertex³Command::set_uv);
        w.property("u", &InsertVertex³Command::u).tag(kTag_Log);
        w.property("v", &InsertVertex³Command::v).tag(kTag_Log);
    }
}
