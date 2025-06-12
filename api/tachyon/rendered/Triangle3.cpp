////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/rendered/Triangle3.hpp>

#include <yq/core/Logging.hpp>
#include <yq/shape/TriangleData.hpp>
#include <yq/shape/shape_utils.hpp>

#include <tachyon/api/Rendered3InfoWriter.hpp>
#include <tachyon/gfx/Shader.hpp>

#include <yq/vector/Vector3.hxx>

#include <tachyon/command/vertex/SetVertex3Command.hpp>
#include <tachyon/command/vertex/SetVertexColorCommand.hpp>
#include <tachyon/command/vertex/SetVertexPoint3Command.hpp>
#include <tachyon/command/vertex/SetVertexUVCommand.hpp>

namespace yq::tachyon {
    void Triangle³::init_info()
    {
        auto w = writer<Triangle³>();
        w.description("Triangle in 3D");
        w.interface<IVertices³>();
        
        w.property("vertex1", &Triangle³::vertex1).setter(&Triangle³::set_vertex1);
        w.property("vertex2", &Triangle³::vertex2).setter(&Triangle³::set_vertex2);
        w.property("vertex3", &Triangle³::vertex3).setter(&Triangle³::set_vertex3);

        w.property("point1", &Triangle³::point1).setter(&Triangle³::set_point1).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("point2", &Triangle³::point2).setter(&Triangle³::set_point2).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("point3", &Triangle³::point3).setter(&Triangle³::set_point3).tag({kTag_Save, kTag_Log, kTag_Print});
        
        w.property("x1", &Triangle³::x1);
        w.property("x2", &Triangle³::x2);
        w.property("x3", &Triangle³::x3);
        
        w.property("y1", &Triangle³::y1);
        w.property("y2", &Triangle³::y2);
        w.property("y3", &Triangle³::y3);

        w.property("z1", &Triangle³::z1);
        w.property("z2", &Triangle³::z2);
        w.property("z3", &Triangle³::z3);

        #if 0
        #endif
        
        w.slot(&Triangle³::on_set_vertex_color);
        w.slot(&Triangle³::on_set_vertex_data);
        w.slot(&Triangle³::on_set_vertex_point);
        w.slot(&Triangle³::on_set_vertex_uv);

        #if 0
        {
            // temporarily here....
            auto& p = w.pipeline();
            
            p.shader("assets/colored.vert");
            p.shader("assets/colored.frag");

            p.vertex(&Triangle³::m_vertex, DataActivity::FIXED)
                .attribute(&ColorVertexData::position)
                .attribute(&ColorVertexData::color)
            ;
            
            p.push_full();
        }
        #endif
    }

    void Triangle³::create_properties(color_k, Rendered³Info::Writer<Triangle³>& w)
    {
        w.property("color1", &Triangle³::color1).setter(&Triangle³::set_color1).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("color2", &Triangle³::color2).setter(&Triangle³::set_color2).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("color3", &Triangle³::color3).setter(&Triangle³::set_color3).tag({kTag_Save, kTag_Log, kTag_Print});
        
        w.property("red1", &Triangle³::red1);
        w.property("red2", &Triangle³::red2);
        w.property("red3", &Triangle³::red3);
        
        w.property("green1", &Triangle³::green1);
        w.property("green2", &Triangle³::green2);
        w.property("green3", &Triangle³::green3);

        w.property("blue1", &Triangle³::blue1);
        w.property("blue2", &Triangle³::blue2);
        w.property("blue3", &Triangle³::blue3);

        w.property("alpha1", &Triangle³::alpha1);
        w.property("alpha2", &Triangle³::alpha2);
        w.property("alpha3", &Triangle³::alpha3);
    }
    
    void Triangle³::create_properties(tex_k, Rendered³Info::Writer<Triangle³>& w)
    {
        w.property("uv1", &Triangle³::uv1).setter(&Triangle³::set_uv1).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("uv2", &Triangle³::uv2).setter(&Triangle³::set_uv2).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("uv3", &Triangle³::uv3).setter(&Triangle³::set_uv3).tag({kTag_Save, kTag_Log, kTag_Print});
        
        w.property("u1", &Triangle³::u1);
        w.property("u2", &Triangle³::u2);
        w.property("u3", &Triangle³::u3);
        
        w.property("v1", &Triangle³::v1);
        w.property("v2", &Triangle³::v2);
        w.property("v3", &Triangle³::v3);
    }

    Triangle³::Triangle³(const Param&p) : Rendered³(p), 
        m_vertex1({
            { 1., 0., 0. },
            { 0., 0. },
            { 1., 0., 0., 1. },
            { 0., 0., 0. }
        }),
        m_vertex2({
            { 0., 1., 0. },
            { 1., 0. },
            { 0., 1., 0., 1. },
            { 0., 0., 0. }
        }),
        m_vertex3({
            { 0., 0., 1. },
            { 0., 1. },
            { 0., 0., 1., 1. },
            { 0., 0., 0. }
        })
    {
    }

    Triangle³::Triangle³(const Vertex³&a, const Vertex³&b, const Vertex³&c, const Param&p) : 
        Rendered³(p), m_vertex1(a), m_vertex2(b), m_vertex3(c)
    {
    }
    
    Triangle³::~Triangle³()
    {
    }

    void Triangle³::_check()
    {
        if(m_dirty){
            mark();
            rebuild();
            m_dirty = false;
        }
    }

    void Triangle³::on_set_vertex_point(const SetVertexPoint³Command& cmd)
    {
        if(cmd.target() != id())
            return ;
        switch(cmd.vertex()){
        case 1:
            set_point1(cmd.point());
            break;
        case 2:
            set_point2(cmd.point());
            break;
        case 3:
            set_point3(cmd.point());
            break;
        }
    }
    
    void Triangle³::on_set_vertex_color(const SetVertexColorCommand& cmd)
    {
        if(cmd.target() != id())
            return ;
        switch(cmd.vertex()){
        case 1:
            set_color1(cmd.color());
            break;
        case 2:
            set_color2(cmd.color());
            break;
        case 3:
            set_color3(cmd.color());
            break;
        }
    }
    
    void Triangle³::on_set_vertex_uv(const SetVertexUVCommand& cmd)
    {
        if(cmd.target() != id())
            return ;
        switch(cmd.vertex()){
        case 1:
            set_uv1(cmd.uv());
            break;
        case 2:
            set_uv2(cmd.uv());
            break;
        case 3:
            set_uv3(cmd.uv());
            break;
        }
    }
    
    void Triangle³::on_set_vertex_data(const SetVertex³Command& cmd)
    {
        if(cmd.target() != id())
            return ;
        switch(cmd.vertex()){
        case 1:
            set_vertex1(cmd.data());
            break;
        case 2:
            set_vertex2(cmd.data());
            break;
        case 3:
            set_vertex3(cmd.data());
            break;
        }
    }

    void Triangle³::set_color1(const RGBA4F&v)
    {
        m_vertex1.color = v;
        m_dirty = true;
    }
    
    void Triangle³::set_color2(const RGBA4F&v)
    {
        m_vertex2.color = v;
        m_dirty = true;
    }
    
    void Triangle³::set_color3(const RGBA4F&v)
    {
        m_vertex3.color = v;
        m_dirty = true;
    }

    void Triangle³::set_point1(const Vector3D& v)
    {
        m_vertex1.point = v;
        m_dirty = true;
    }
    
    void Triangle³::set_point2(const Vector3D& v)
    {
        m_vertex2.point = v;
        m_dirty = true;
    }
    
    void Triangle³::set_point3(const Vector3D& v)
    {
        m_vertex3.point = v;
        m_dirty = true;
    }

    void    Triangle³::set_uv1(const UV2F&v)
    {
        m_vertex1.uv    = v;
        m_dirty = true;
    }
    
    void    Triangle³::set_uv2(const UV2F&v)
    {
        m_vertex2.uv    = v;
        m_dirty = true;
    }
    
    void    Triangle³::set_uv3(const UV2F&v)
    {
        m_vertex3.uv    = v;
        m_dirty = true;
    }

    void    Triangle³::set_vertex1(const Vertex³&v)
    {
        m_vertex1   = v;
        m_dirty = true;
    }
    
    void    Triangle³::set_vertex2(const Vertex³&v)
    {
        m_vertex2   = v;
        m_dirty = true;
    }
    
    void    Triangle³::set_vertex3(const Vertex³&v)
    {
        m_vertex3   = v;
        m_dirty = true;
    }

    Execution Triangle³::setup(const Context&ctx)
    {
        _check();
        return Rendered³::setup(ctx);
    }
    
    Execution Triangle³::tick(const Context&ctx) 
    {
        _check();
        return Rendered³::tick(ctx);
    }

    Vertex³   Triangle³::vertex(size_t n) const 
    {
        switch(n){
        case 1:
            return m_vertex1;
        case 2:
            return m_vertex2;
        case 3:
            return m_vertex3;
        default:    
            return {};
        }
    }
    
    Vector3D    Triangle³::vertex(size_t n, point_k) const 
    {
        switch(n){
        case 1:
            return m_vertex1.point;
        case 2:
            return m_vertex2.point;
        case 3:
            return m_vertex3.point;
        default:
            return {};
        }
    }
    
    RGBA4F      Triangle³::vertex(size_t n, color_k) const 
    {
        switch(n){
        case 1:
            return m_vertex1.color;
        case 2:
            return m_vertex2.color;
        case 3:
            return m_vertex3.color;
        default:
            return {};
        }
    }
    
    UV2F        Triangle³::vertex(size_t n, tex_k) const 
    {
        switch(n){
        case 1:
            return m_vertex1.uv;
        case 2:
            return m_vertex2.uv;
        case 3:
            return m_vertex3.uv;
        default:
            return {};
        }
    }
    
    void        Triangle³::vertex(size_t n, set_k, const Vertex³&v) 
    {
        switch(n){
        case 1:
            set_vertex1(v);
            break;
        case 2:
            set_vertex2(v);
            break;
        case 3:
            set_vertex3(v);
            break;
        }
    }
    
    void        Triangle³::vertex(size_t n, set_k, const Vector3D&v) 
    {
        switch(n){
        case 1:
            set_point1(v);
            break;
        case 2:
            set_point2(v);
            break;
        case 3:
            set_point3(v);
            break;
        }
    }
    
    void        Triangle³::vertex(size_t n, set_k, color_k, const RGBA4F&v) 
    {
        switch(n){
        case 1:
            set_color1(v);
            break;
        case 2:
            set_color2(v);
            break;
        case 3:
            set_color3(v);
            break;
        }
    }
    
    void        Triangle³::vertex(size_t n, set_k, tex_k, const UV2F&v) 
    {
        switch(n){
        case 1:
            set_uv1(v);
            break;
        case 2:
            set_uv2(v);
            break;
        case 3:
            set_uv3(v);
            break;
        }
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Triangle³)
