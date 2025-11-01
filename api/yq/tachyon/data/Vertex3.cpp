////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Vertex3.hpp"
#include <yq/math/glm.hpp>
#include <yq/meta/Init.hpp>
#include <yq/tags.hpp>
#include <tachyon/data/ColorVertex2D.hpp>
#include <tachyon/data/ColorVertex3D.hpp>

YQ_TYPE_IMPLEMENT(yq::tachyon::Vertex³)

namespace yq::tachyon {
    Vertex³     vertex³(const ColorVertex2D& v)
    {
        return Vertex³{ 
            .point=Vector3D(v.position.x, v.position.y, 0.), 
            .color=rgba(RGB3F(v.color), 1.)
        };
    }
    
    Vertex³     vertex³(const ColorVertex3D& v)
    {
        return Vertex³{ 
            .point=v.position,
            .color=rgba(RGB3F(v.color), 1.)
        };
    }

    static void    reg_vertex3()
    {
        auto w  = writer<Vertex³>();
        w.property("point",  &Vertex³::point).tag(kTag_Save);
        w.property("color",  &Vertex³::color).tag(kTag_Save);
        w.property("uv",     &Vertex³::uv).tag(kTag_Save); 
        w.property("normal", &Vertex³::normal).tag(kTag_Save);
    }
    
    YQ_INVOKE(reg_vertex3();)
}
