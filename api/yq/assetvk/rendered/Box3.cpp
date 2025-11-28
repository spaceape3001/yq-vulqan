////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Box3.hpp"

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Rendered3MetaWriter.hpp>
#include <yq/tachyon/asset/Shader.hpp>


#include <yq/tachyon/aspect/AVertices3.hxx>
#include <yq/tachyon/aspect/AVertices3Writer.hxx>
#include <yq/tachyon/aspect/ASize3Writer.hxx>

#include <yq/shape/AxBox3.hxx>
#include <yq/shape/Size3.hxx>
#include <yq/vector/Vector3.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Box³);

namespace yq::tachyon {
    
    const uint16_t   Box³::s_kIndices[] = { 
        0, 2, 3, 0, 3, 1,   // bottom face
        4, 5, 7, 7, 6, 4,   // top face
        0, 1, 5, 5, 4, 0,   // south face
        2, 0, 6, 0, 4, 6,   // west face,
        2, 7, 3, 6, 7, 2,   // north face
        3, 7, 5, 5, 1, 3    // east face
    };
    IBO<uint16_t>    Box³::s_indices(s_kIndices);

    void Box³::init_meta()
    {
        auto w = writer<Box³>();
        w.description("3D Box render object");
        MyVertices::init_meta(w);
        ASize³::init_meta(w);
        w.abstract();
        
        w.property("point_bsw", &Box³::point_bsw);
        w.property("point_bse", &Box³::point_bse);
        w.property("point_bnw", &Box³::point_bnw);
        w.property("point_bne", &Box³::point_bne);
        w.property("point_tsw", &Box³::point_tsw);
        w.property("point_tse", &Box³::point_tse);
        w.property("point_tnw", &Box³::point_tnw);
        w.property("point_tne", &Box³::point_tne);

        w.property("x_bsw", &Box³::x_bsw);
        w.property("x_bse", &Box³::x_bse);
        w.property("x_bnw", &Box³::x_bnw);
        w.property("x_bne", &Box³::x_bne);
        w.property("x_tsw", &Box³::x_tsw);
        w.property("x_tse", &Box³::x_tse);
        w.property("x_tnw", &Box³::x_tnw);
        w.property("x_tne", &Box³::x_tne);

        w.property("y_bsw", &Box³::y_bsw);
        w.property("y_bse", &Box³::y_bse);
        w.property("y_bnw", &Box³::y_bnw);
        w.property("y_bne", &Box³::y_bne);
        w.property("y_tsw", &Box³::y_tsw);
        w.property("y_tse", &Box³::y_tse);
        w.property("y_tnw", &Box³::y_tnw);
        w.property("y_tne", &Box³::y_tne);

        w.property("z_bsw", &Box³::z_bsw);
        w.property("z_bse", &Box³::z_bse);
        w.property("z_bnw", &Box³::z_bnw);
        w.property("z_bne", &Box³::z_bne);
        w.property("z_tsw", &Box³::z_tsw);
        w.property("z_tse", &Box³::z_tse);
        w.property("z_tnw", &Box³::z_tnw);
        w.property("z_tne", &Box³::z_tne);
    }

    Box³::Param    Box³::set_position(const AxBox3D& bx, const Param& p)
    {
        Param ret   = p;
        ret.position  = bx.center();
        return ret;
    }
    
    Box³::Box³(const Size3D& sz, const Param& p) : Shape³(p)
    {
        m_size  = sz;
        
        for(auto& v : m_vertices)
            v.color = { 1., 1., 1., 1. };
    }

    Box³::Box³(const AxBox3D& bx, const Param& p) : Box³(bx.size(), set_position(bx, p))
    {
    }
    
    Box³::~Box³()
    {
    }

    void    Box³::rebuild() 
    {
        Shape³::rebuild();
        
        double      hx  = 0.5*m_size.x;
        double      hy  = 0.5*m_size.y;
        double      hz  = 0.5*m_size.z;
        
        vertex_bsw().point  = { -hx, -hy, -hz };
        vertex_bse().point  = {  hx, -hy, -hz };
        vertex_bnw().point  = { -hx,  hy, -hz };
        vertex_bne().point  = {  hx,  hy, -hz };
        vertex_tsw().point  = { -hx, -hy,  hz };
        vertex_tse().point  = {  hx, -hy,  hz };
        vertex_tnw().point  = { -hx,  hy,  hz };
        vertex_tne().point  = {  hx,  hy,  hz };
    }
}
