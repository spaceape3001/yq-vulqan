////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GradTriangle3.hpp"
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/tags.hpp>

#include <yq/tachyon/api/Rendered3MetaWriter.hpp>
#include <yq/tachyon/asset/Shader.hpp>

#include <yq/vector/Vector3.hxx>


namespace yq::tachyon {
    void GradTriangle³::init_meta()
    {
        auto w = writer<GradTriangle³>(UNSAFE);
        w.description("Gradient Triangle in 3D");
        w.category("Shape");

        w.property("color1", &GradTriangle³::color1).setter(&GradTriangle³::set_color1).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("color2", &GradTriangle³::color2).setter(&GradTriangle³::set_color2).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("color3", &GradTriangle³::color3).setter(&GradTriangle³::set_color3).tag({kTag_Save, kTag_Log, kTag_Print});

        w.property("red1", &GradTriangle³::red1);
        w.property("red2", &GradTriangle³::red2);
        w.property("red3", &GradTriangle³::red3);

        w.property("green1", &GradTriangle³::green1);
        w.property("green2", &GradTriangle³::green2);
        w.property("green3", &GradTriangle³::green3);
        
        w.property("blue1", &GradTriangle³::blue1);
        w.property("blue2", &GradTriangle³::blue2);
        w.property("blue3", &GradTriangle³::blue3);
        
        w.property("alpha1", &GradTriangle³::alpha1);
        w.property("alpha2", &GradTriangle³::alpha2);
        w.property("alpha3", &GradTriangle³::alpha3);

        auto& p = w.pipeline();
        p.shader("resources/shape3/gradient.vert");
        p.shader("resources/shape3/gradient.frag");

        p.vertex(&GradTriangle³::m_vbo, DataActivity::DYNAMIC)
            .attribute(&VertexC::position)
            .attribute(&VertexC::color)
        ;
        p.push_full();
    }
    
    GradTriangle³::GradTriangle³(const Param&p) : Triangle³(p)
    {
        rebuild();
    }

    GradTriangle³::GradTriangle³(const Vertex³&a, const Vertex³&b, const Vertex³&c, const Param&p) : 
        Triangle³(a,b,c,p)
    {
        rebuild();
    }
  
    GradTriangle³::GradTriangle³(const TriangleData<ColorVertex3D>&data, const Param& p) : 
        Triangle³(data, p)
    {
        rebuild();
    }
    
    GradTriangle³::GradTriangle³(const TriangleData<ColorVertex2D>&data, const Param& p) :
        Triangle³(data, p)
    {
        rebuild();
    }
    
    GradTriangle³::~GradTriangle³()
    {
    }

    void GradTriangle³::set_color1(const RGBA4F&v)
    {
        vertex1().color = v;
        mark();
    }
    
    void GradTriangle³::set_color2(const RGBA4F&v)
    {
        vertex2().color = v;
        mark();
    }
    
    void GradTriangle³::set_color3(const RGBA4F&v)
    {
        vertex3().color = v;
        mark();
    }
    
    void    GradTriangle³::rebuild()
    {
        m_vbo   = {
            vc(vertex1()), vc(vertex2()), vc(vertex3())
        };
    }
    
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::GradTriangle³)
