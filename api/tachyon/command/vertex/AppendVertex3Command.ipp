////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AppendVertex3Command.hpp"
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AppendVertex³Command)

namespace yq::tachyon {

    AppendVertex³Command::AppendVertex³Command(const Header&h, const Vertex³&data) : 
        VertexCommand(h), m_data(data)
    {
    }

    AppendVertex³Command::AppendVertex³Command(const AppendVertex³Command& cp, const Header& h) : 
        VertexCommand(cp, h), m_data(cp.m_data)
    {
    }
    
    AppendVertex³Command::~AppendVertex³Command()
    {
    }

    PostCPtr    AppendVertex³Command::clone(rebind_k, const Header&h) const 
    {
        return new AppendVertex³Command(*this, h);
    }
    
    void        AppendVertex³Command::set_color(const RGBA4F&v)
    {
        m_data.color = v;
    }

    void        AppendVertex³Command::set_data(const Vertex³&v)
    {
        m_data = v;
    }

    void        AppendVertex³Command::set_normal(const Vector3F&v)
    {
        m_data.normal = v;
    }

    void        AppendVertex³Command::set_point(const Vector3D&v)
    {
        m_data.point = v;
    }

    void        AppendVertex³Command::set_uv(const UV2F&v)
    {
        m_data.uv = v;
    }

    ////////////////////////////////////////////////////////////////////////////

    void AppendVertex³Command::init_meta()
    {
        auto w = writer<AppendVertex³Command>();
        w.description("Append Vertex 3D Command");

        w.property("data", &AppendVertex³Command::m_data).tag(kTag_Save);
        
        w.property("color", &AppendVertex³Command::color).setter(&AppendVertex³Command::set_color);
        w.property("red", &AppendVertex³Command::red).tag(kTag_Log);
        w.property("green", &AppendVertex³Command::green).tag(kTag_Log);
        w.property("blue", &AppendVertex³Command::blue).tag(kTag_Log);
        w.property("alpha", &AppendVertex³Command::alpha).tag(kTag_Log);
        
        w.property("point", &AppendVertex³Command::point).setter(&AppendVertex³Command::set_point);
        w.property("x", &AppendVertex³Command::x).tag(kTag_Log);
        w.property("y", &AppendVertex³Command::y).tag(kTag_Log);
        w.property("z", &AppendVertex³Command::z).tag(kTag_Log);
        
        w.property("normal", &AppendVertex³Command::normal).setter(&AppendVertex³Command::set_normal);
        w.property("nx", &AppendVertex³Command::nx).tag(kTag_Log);
        w.property("ny", &AppendVertex³Command::ny).tag(kTag_Log);
        w.property("nz", &AppendVertex³Command::nz).tag(kTag_Log);
        
        w.property("uv", &AppendVertex³Command::uv).setter(&AppendVertex³Command::set_uv);
        w.property("u", &AppendVertex³Command::u).tag(kTag_Log);
        w.property("v", &AppendVertex³Command::v).tag(kTag_Log);
    }
}
