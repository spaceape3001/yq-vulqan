////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/rendered/ColorTriangle3.hpp>
#include <tachyon/api/Rendered3InfoWriter.hpp>
#include <tachyon/gfx/Shader.hpp>
#include <tachyon/tags.hpp>

#include <yq/core/Logging.hpp>
#include <yq/shape/TriangleData.hpp>
#include <yq/shape/shape_utils.hpp>

#include <yq/vector/Vector3.hxx>

namespace yq::tachyon {

    void ColorTriangle³::init_info()
    {
        auto w = writer<ColorTriangle³>();
        w.description("Color Triangle in 3D");
        create_properties(COLOR, w);

        {
            auto& p = w.pipeline();
            
            p.shader("assets/colored.vert");
            p.shader("assets/colored.frag");

            p.vertex(&ColorTriangle³::m_vertex, DataActivity::DYNAMIC)
                .attribute(&Vertex::position)
                .attribute(&Vertex::color)
            ;
            
            p.push_full();
        }
    }

    ColorTriangle³::Vertex   ColorTriangle³::vq(const Vertex³&v)
    {
        return {
            .position   = { v.point.x, v.point.y, v.point.z },
            .color      = { v.color.red, v.color.green, v.color.blue, v.color.alpha }
        };
    }

    ColorTriangle³::ColorTriangle³(const Vertex³&a, const Vertex³&b, const Vertex³&c, const Param& p) :
        Triangle³(a, b, c, p)
    {
        rebuild();
    }

    ColorTriangle³::ColorTriangle³(const TriangleData<ColorVertex2D>& data, const Param& p) : 
        ColorTriangle³(vertex³(data.a), vertex³(data.b), vertex³(data.c), p)
    {
    }

    ColorTriangle³::ColorTriangle³(const TriangleData<ColorVertex3D>& data, const Param& p) : 
        ColorTriangle³(vertex³(data.a), vertex³(data.b), vertex³(data.c), p)
    {
    }
    
    ColorTriangle³::ColorTriangle³(const Param&p) : Triangle³(p)
    {
        rebuild();
    }
    
    ColorTriangle³::~ColorTriangle³()
    {
    }

    void    ColorTriangle³::rebuild() 
    {
        m_vertex    = { vq(m_vertex1), vq(m_vertex2), vq(m_vertex3) };
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::ColorTriangle³)
