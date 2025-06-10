////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IVertices3.hpp"
#include <tachyon/data/Vertex3.hpp>
#include <tachyon/proxy/PVertices3.hpp>
#include <tachyon/api/InterfaceInfoWriter.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IVertices³)

namespace yq::tachyon {
    void IVertices³::init_info()
    {
        auto w = writer<IVertices³>();
        w.description("3D Vertices");
    }

    Vertex³      IVertices³::vertex(size_t n) const
    {
        return Vertex³{ vertex(n, POINT), vertex(n, TEX), vertex(n, COLOR), vertex(n, NORMAL) };
    }
    
    RGBA4F      IVertices³::vertex(size_t, color_k) const
    {
        return {};
    }
    
    UV2F        IVertices³::vertex(size_t, tex_k) const
    {
        return {};
    }
    
    Vector3F    IVertices³::vertex(size_t, normal_k) const
    {
        return {};
    }
    
    void        IVertices³::vertex(size_t n, set_k, const Vertex³& v)
    {
        vertex(n, SET, v.point);
        vertex(n, SET, COLOR, v.color);
        vertex(n, SET, TEX, v.uv);
        vertex(n, SET, NORMAL, v.normal);
    }

    IVertices³::IVertices³() = default;
    IVertices³::~IVertices³() = default;
}
