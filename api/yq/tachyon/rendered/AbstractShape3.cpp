////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AbstractShape3.hpp"
#include <yq/tachyon/api/Rendered3MetaWriter.hpp>
#include <yq/tachyon/aspect/ABgColorWriter.hxx>
#include <yq/tachyon/aspect/AColorWriter.hxx>
#include <yq/tachyon/aspect/ADrawModeWriter.hxx>
#include <yq/tachyon/data/Vertex3.hpp>
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/logging.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::AbstractShape³)

namespace yq::tachyon {
    void AbstractShape³::init_meta()
    {
        auto w = writer<AbstractShape³>();
        w.abstract();
        w.description("Abstract 3D shape");
        //ADrawMode::init_meta(w);
        //AColor::init_meta(w);
        //ABgColor::init_meta(w);
    }
    
    AbstractShape³::VertexC  AbstractShape³::vc(const Vertex³&v)
    {
        return {
            .color      = { v.color.red, v.color.green, v.color.blue, v.color.alpha },
            .position   = { v.point.x, v.point.y, v.point.z }
        };
    }
    
    AbstractShape³::VertexCT AbstractShape³::vct(const Vertex³&v)
    {
        return {
            .color      = { v.color.red, v.color.green, v.color.blue, v.color.alpha },
            .position   = { v.point.x, v.point.y, v.point.z },
            .uv         = { v.uv.u, v.uv.v }
        };
    }
    
    AbstractShape³::VertexT  AbstractShape³::vt(const Vertex³&v)
    {
        return {
            .position   = { v.point.x, v.point.y, v.point.z },
            .uv         = { v.uv.u, v.uv.v }
        };
    }
    
    AbstractShape³::VertexS  AbstractShape³::vs(const Vertex³&v)
    {
        return {
            .position   = { v.point.x, v.point.y, v.point.z }
        };
    }
    

    AbstractShape³::AbstractShape³(const Param& p) : Rendered³(p)
    {
        //m_color     = p.color;
        //m_bgcolor   = p.bgcolor;
        //m_drawMode  = p.draw_mode;
        //mark();
    }
    
    AbstractShape³::~AbstractShape³()
    {
    }

    Execution   AbstractShape³::setup(const Context& ctx) 
    {
        rebuild();
        return Rendered³::setup(ctx);
    }
    
    Execution   AbstractShape³::tick(const Context&ctx) 
    {
        if(dirty())
            rebuild();
        return Rendered³::tick(ctx);
    }
}
