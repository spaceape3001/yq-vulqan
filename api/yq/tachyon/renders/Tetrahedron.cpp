////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Tetrahedron.hpp"

#include <yq/shape/TetrahedronData.hpp>
#include <yq/shape/shape_utils.hpp>

#include <yq/tachyon/api/Rendered³InfoWriter.hpp>
#include <yq/tachyon/api/Shader.hpp>

#include <yq/vector/Vector3.hxx>

namespace yq::tachyon {
    void Tetrahedron³::init_info()
    {
        static const uint16_t   kIndices[] = { 1, 2, 3, 0, 3, 2, 0, 1, 3, 0, 2, 1 };
        static IBO<uint16_t>    indices(kIndices);
    
        auto w = writer<Tetrahedron³>();
        {
            auto& p = w.pipeline();
            
            p.shader("assets/colored.vert");
            p.shader("assets/colored.frag");

            p.vertex(&Tetrahedron³::m_vertex, DataActivity::FIXED)
                .attribute(&ColorVertexData::position)
                .attribute(&ColorVertexData::color)
            ;
            
            p.index(indices, DataActivity::COMMON);
            p.push_full();
        }
    }

    Tetrahedron³::Tetrahedron³(const TetrahedronData<ColorVertex3D>&tri)
    {
        m_vertex    = { tri.a, tri.b, tri.c, tri.d};
    }
    
    Tetrahedron³::~Tetrahedron³()
    {
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Tetrahedron³)
