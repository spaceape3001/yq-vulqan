////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Quadrilateral.hpp"

#include <yq/shape/QuadrilateralData.hpp>
#include <yq/shape/QuadrilateralData.hpp>
#include <yq/shape/shape_utils.hpp>
#include <yq/vector/Vector3.hxx>

#include <yq/tachyon/api/Rendered3InfoWriter.hpp>
#include <yq/tachyon/api/Shader.hpp>


namespace yq::tachyon {
    void Quadrilateral3::init_info()
    {
        static IB1<uint16_t> kIndices({ 0, 1, 2, 2, 3, 0 });
    
        auto w = writer<Quadrilateral3>();
        
        {
            auto& p = w.pipeline();
            
            p.shader("assets/colored.vert");
            p.shader("assets/colored.frag");

            p.vertex(&Quadrilateral3::m_vertex, DataActivity::FIXED)
                .attribute(&ColorVertexData::position)
                .attribute(&ColorVertexData::color)
            ;
            
            p.index(kIndices, DataActivity::COMMON);
            p.push_full();
        }
    }

    Quadrilateral3::Quadrilateral3(const QuadrilateralData<ColorVertex2D>&quad, const Param& p) : Rendered3(p)
    {
        m_vertex = { quad.a, quad.b, quad.c, quad.d};
    }
    
    Quadrilateral3::~Quadrilateral3()
    {
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Quadrilateral3)
