////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Diamond3.hpp"

#include <tachyon/logging.hpp>
#include <tachyon/api/Rendered3MetaWriter.hpp>
#include <tachyon/resource/Shader.hpp>

#include <tachyon/aspect/AVertices3.hxx>
#include <tachyon/aspect/AVertices3Writer.hxx>
#include <tachyon/aspect/ASize3Writer.hxx>

#include <yq/shape/AxBox3.hxx>
#include <yq/shape/Size3.hxx>
#include <yq/vector/Vector3.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Diamond³);

namespace yq::tachyon {
    
    const uint16_t   Diamond³::s_kIndices[] = { 
        0, 2, 4,            // east-north-top
        2, 1, 4,            // north-west-top
        1, 3, 4,            // west-south-top
        3, 0, 4,            // south-east-top
        0, 3, 5,            // east-south-bottom
        3, 1, 5,            // south-west-bottom
        1, 2, 5,            // west-north-bottom
        2, 0, 5             // north-east-bottom
    };
    IBO<uint16_t>    Diamond³::s_indices(s_kIndices);

    void Diamond³::init_meta()
    {
        auto w = writer<Diamond³>();
        w.description("3D diamond render object");
        MyVertices::init_meta(w);
        ASize³::init_meta(w);
        w.abstract();
        
        w.property("point_east", &Diamond³::point_east);
        w.property("point_west", &Diamond³::point_west);
        w.property("point_north", &Diamond³::point_north);
        w.property("point_south", &Diamond³::point_south);
        w.property("point_top", &Diamond³::point_top);
        w.property("point_bottom", &Diamond³::point_bottom);

        w.property("x_east", &Diamond³::x_east);
        w.property("x_west", &Diamond³::x_west);
        w.property("x_north", &Diamond³::x_north);
        w.property("x_south", &Diamond³::x_south);
        w.property("x_top", &Diamond³::x_top);
        w.property("x_bottom", &Diamond³::x_bottom);

        w.property("y_east", &Diamond³::y_east);
        w.property("y_west", &Diamond³::y_west);
        w.property("y_north", &Diamond³::y_north);
        w.property("y_south", &Diamond³::y_south);
        w.property("y_top", &Diamond³::y_top);
        w.property("y_bottom", &Diamond³::y_bottom);

        w.property("z_east", &Diamond³::z_east);
        w.property("z_west", &Diamond³::z_west);
        w.property("z_north", &Diamond³::z_north);
        w.property("z_south", &Diamond³::z_south);
        w.property("z_top", &Diamond³::z_top);
        w.property("z_bottom", &Diamond³::z_bottom);
    }

    Diamond³::Param    Diamond³::set_position(const AxBox3D& bx, const Param& p)
    {
        Param ret   = p;
        ret.position  = bx.center();
        return ret;
    }
    
    Diamond³::Diamond³(const Size3D& sz, const Param& p) : AbstractShape³(p)
    {
        m_size  = sz;
        
        for(auto& v : m_vertices)
            v.color = { 1., 1., 1., 1. };
    }

    Diamond³::Diamond³(const AxBox3D& bx, const Param& p) : Diamond³(bx.size(), set_position(bx, p))
    {
    }
    
    Diamond³::~Diamond³()
    {
    }

    void    Diamond³::rebuild() 
    {
        AbstractShape³::rebuild();
        
        double      hx  = 0.5*m_size.x;
        double      hy  = 0.5*m_size.y;
        double      hz  = 0.5*m_size.z;
        
        vertex_east().point     = { -hx,  0.,  0. };
        vertex_west().point     = {  hx,  0.,  0. };
        vertex_north().point    = {  0.,  hy,  0. };
        vertex_south().point    = {  0., -hy,  0. };
        vertex_top().point      = {  0.,  0.,  hz };
        vertex_bottom().point   = {  0.,  0., -hz };
    }
}
