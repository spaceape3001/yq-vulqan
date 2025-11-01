////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/rendered/GradTetrahedron3.hpp>
#include <yq/tachyon/logging.hpp>

#include <yq/color/colors.hpp>
#include <yq/shape/TetrahedronData.hpp>
#include <yq/shape/shape_utils.hpp>

#include <yq/tachyon/asset/Shader.hpp>
#include <yq/tachyon/api/Rendered3MetaWriter.hpp>

#include <yq/vector/Vector3.hxx>

#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    void GradTetrahedron³::init_meta()
    {
        auto w = writer<GradTetrahedron³>();
        w.description("Tetrahedron in 3D with gradient colros");
        w.category("Shape");

        w.property("color1", &GradTetrahedron³::color1).setter(&GradTetrahedron³::set_color1).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("color2", &GradTetrahedron³::color2).setter(&GradTetrahedron³::set_color2).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("color3", &GradTetrahedron³::color3).setter(&GradTetrahedron³::set_color3).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("color4", &GradTetrahedron³::color4).setter(&GradTetrahedron³::set_color4).tag({kTag_Save, kTag_Log, kTag_Print});

        w.property("red1", &GradTetrahedron³::red1);
        w.property("red2", &GradTetrahedron³::red2);
        w.property("red3", &GradTetrahedron³::red3);
        w.property("red4", &GradTetrahedron³::red4);

        w.property("green1", &GradTetrahedron³::green1);
        w.property("green2", &GradTetrahedron³::green2);
        w.property("green3", &GradTetrahedron³::green3);
        w.property("green4", &GradTetrahedron³::green4);
        
        w.property("blue1", &GradTetrahedron³::blue1);
        w.property("blue2", &GradTetrahedron³::blue2);
        w.property("blue3", &GradTetrahedron³::blue3);
        w.property("blue4", &GradTetrahedron³::blue4);
        
        w.property("alpha1", &GradTetrahedron³::alpha1);
        w.property("alpha2", &GradTetrahedron³::alpha2);
        w.property("alpha3", &GradTetrahedron³::alpha3);
        w.property("alpha4", &GradTetrahedron³::alpha4);

        auto& p = w.pipeline();
        
        p.shader("resources/shape3/gradient.vert");
        p.shader("resources/shape3/gradient.frag");

        p.vertex(&GradTetrahedron³::m_vbo, DataActivity::DYNAMIC)
            .attribute(&VertexC::position)
            .attribute(&VertexC::color)
        ;

        p.index(s_indices, DataActivity::COMMON);
        p.push_full();
    }

    GradTetrahedron³::GradTetrahedron³(const Vertex³&a, const Vertex³&b, const Vertex³&c, const Vertex³&d, const Param&p) : 
        Tetrahedron³(a,b,c,d,p)
    {
    }
  
    GradTetrahedron³::GradTetrahedron³(const TetrahedronData<ColorVertex3D>&data, const Param& p) : 
        Tetrahedron³(data, p)
    {
    }

    GradTetrahedron³::GradTetrahedron³(const Param&p) : Tetrahedron³(p)
    {
    }

    GradTetrahedron³::~GradTetrahedron³()
    {
    }


    void GradTetrahedron³::set_color1(const RGBA4F&v)
    {
        vertex1().color = v;
        mark();
    }
    
    void GradTetrahedron³::set_color2(const RGBA4F&v)
    {
        vertex2().color = v;
        mark();
    }
    
    void GradTetrahedron³::set_color3(const RGBA4F&v)
    {
        vertex3().color = v;
        mark();
    }

    void GradTetrahedron³::set_color4(const RGBA4F&v)
    {
        vertex4().color = v;
        mark();
    }

    void    GradTetrahedron³::rebuild() 
    {
        m_vbo = {
            vc(vertex1()), vc(vertex2()), vc(vertex3()), vc(vertex4())
        };
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::GradTetrahedron³)
