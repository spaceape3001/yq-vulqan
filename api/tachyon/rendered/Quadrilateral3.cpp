////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/rendered/Quadrilateral3.hpp>

#include <yq/shape/QuadrilateralData.hpp>
#include <yq/shape/QuadrilateralData.hpp>
#include <yq/shape/shape_utils.hpp>
#include <yq/vector/Vector3.hxx>

#include <tachyon/api/Rendered3InfoWriter.hpp>
#include <tachyon/gfx/Shader.hpp>


namespace yq::tachyon {
    void Quadrilateral³::init_info()
    {
        static IB1<uint16_t> kIndices({ 0, 1, 2, 2, 3, 0 });
    
        auto w = writer<Quadrilateral³>();
        
        {
            auto& p = w.pipeline();
            
            p.shader("assets/colored.vert");
            p.shader("assets/colored.frag");

            p.vertex(&Quadrilateral³::m_vertex, DataActivity::FIXED)
                .attribute(&ColorVertexData::position)
                .attribute(&ColorVertexData::color)
            ;
            
            p.index(kIndices, DataActivity::COMMON);
            p.push_full();
        }
    }

    Quadrilateral³::Quadrilateral³(const QuadrilateralData<ColorVertex2D>&quad, const Param& p) : Rendered³(p)
    {
        m_vertex = { quad.a, quad.b, quad.c, quad.d};
    }
    
    Quadrilateral³::~Quadrilateral³()
    {
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Quadrilateral³)
