////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Shape3.hpp"
#include <yq/math/UV.hpp>
#include <yq/math/UVW.hpp>
#include <yq/tachyon/api/Rendered3MetaWriter.hpp>
#include <yq/tachyon/aspect/ABgColorWriter.hxx>
#include <yq/tachyon/aspect/AColorWriter.hxx>
#include <yq/tachyon/aspect/ADrawModeWriter.hxx>
#include <yq/tachyon/aspect/AMaterialWriter.hxx>
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/data/Vertex3.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/vector/Vector4.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Shape³)

namespace yq::tachyon {

    glm::vec3    Shape³::gfx(const RGB3F&v)
    {
        return { v.red, v.green, v.blue };
    }
    
    glm::vec4    Shape³::gfx(const RGBA4F&v)
    {
        return { v.red, v.green, v.blue, v.alpha };
    }

    glm::vec2    Shape³::gfx(const UV2F&v)
    {
        return { v.u, v.v };
    }
    
    glm::vec3    Shape³::gfx(const UVW3F&v)
    {
        return { v.u, v.v, v.w };
    }
    
    glm::dvec2   Shape³::gfx(const Vector2D&v)
    {
        return { v.x, v.y };
    }

    glm::vec2    Shape³::gfx(const Vector2F&v)
    {
        return { v.x, v.y };
    }
    
    glm::dvec3   Shape³::gfx(const Vector3D&v)
    {
        return { v.x, v.y, v.z };
    }

    glm::vec3    Shape³::gfx(const Vector3F&v)
    {
        return { v.x, v.y, v.z };
    }
    
    glm::dvec4   Shape³::gfx(const Vector4D&v)
    {
        return { v.x, v.y, v.z, v.w };
    }

    glm::vec4    Shape³::gfx(const Vector4F&v)
    {
        return { v.x, v.y, v.z, v.w };
    }

    Shape³::VertexC      Shape³::vc(const Vertex³&v)
    {
        return {
            .color      = gfx(v.color),
            .position   = gfx(v.point)
        };
    }
    
    Shape³::VertexCT     Shape³::vct(const Vertex³&v)
    {
        return {
            .color      = gfx(v.color),
            .position   = gfx(v.point),
            .uv         = gfx(v.uv)
        };
    }
    
    Shape³::VertexT      Shape³::vt(const Vertex³&v)
    {
        return {
            .position   = gfx(v.point),
            .uv         = gfx(v.uv)
        };
    }
    
    Shape³::VertexS      Shape³::vs(const Vertex³&v)
    {
        return {
            .position   = gfx(v.point)
        };
    }
    
    Shape³::VertexC      Shape³::vtx(const Vector3D&v, const RGBA4F&c)
    {
        return {
            .color      = gfx(c),
            .position   = gfx(v)
        };
    }
    
    Shape³::VertexC      Shape³::vtx(const Vector3F&v, const RGBA4F&c)
    {
        return {
            .color      = gfx(c),
            .position   = gfx(v)
        };
    }
    
    Shape³::VertexT      Shape³::vtx(const Vector3D&v, const UV2F&t)
    {
        return {
            .position   = gfx(v),
            .uv         = gfx(t)
        };
    }
    
    Shape³::VertexT      Shape³::vtx(const Vector3F&v, const UV2F&t)
    {
        return {
            .position   = gfx(v),
            .uv         = gfx(t)
        };
    }
    
    Shape³::VertexCT     Shape³::vtx(const Vector3D&v, const RGBA4F&c, const UV2F&t)
    {
        return {
            .color      = gfx(c),
            .position   = gfx(v),
            .uv         = gfx(t)
        };
    }
    
    Shape³::VertexCT     Shape³::vtx(const Vector3F&v, const RGBA4F&c, const UV2F&t)
    {
        return {
            .color      = gfx(c),
            .position   = gfx(v),
            .uv         = gfx(t)
        };
    }
    
    Shape³::VertexS      Shape³::vtx(const Vector3D&v)
    {
        return {
            .position   = gfx(v)
        };
    }
    
    Shape³::VertexS      Shape³::vtx(const Vector3F&v)
    {
        return {
            .position   = gfx(v)
        };
    }

////////////////////////////////////////////////////////////////////////////////

    void Shape³::init_meta()
    {
        auto w = writer<Shape³>();
        w.abstract();
        w.description("Abstract 3D shape");
        ABgColor::init_meta(w);
        AColor::init_meta(w);
        ADrawMode::init_meta(w);
        AMaterial::init_meta(w);
    }

    Shape³::Shape³(const Param& p) : Rendered³(p)
    {
        m_color     = p.color;
        m_bgcolor   = p.bgcolor;
        m_drawMode  = p.draw_mode;
        mark();
    }
    
    Shape³::~Shape³()
    {
    }

    Execution   Shape³::setup(const Context& ctx) 
    {
        rebuild();
        return Rendered³::setup(ctx);
    }
    
    Execution   Shape³::tick(const Context&ctx) 
    {
        if(dirty())
            rebuild();
        return Rendered³::tick(ctx);
    }
}
