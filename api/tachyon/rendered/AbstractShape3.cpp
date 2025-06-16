////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AbstractShape3.hpp"
#include <tachyon/api/Rendered3InfoWriter.hpp>
#include <tachyon/aspect/ABgColorWriter.hxx>
#include <tachyon/aspect/AColorWriter.hxx>
#include <tachyon/aspect/ADrawModeWriter.hxx>
#include <tachyon/data/Vertex3.hpp>
#include <tachyon/gfx/Texture.hpp>
#include <tachyon/logging.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::AbstractShape³)

namespace yq::tachyon {
    void AbstractShape³::init_info()
    {
        auto w = writer<AbstractShape³>();
        w.abstract();
        w.description("Abstract 3D shape");
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
    }
    
    AbstractShape³::~AbstractShape³()
    {
    }

    Execution   AbstractShape³::setup(const Context& ctx) 
    {
        if(dirty())
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
