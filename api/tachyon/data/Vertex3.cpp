////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Vertex3.hpp"
#include <yq/meta/Init.hpp>
#include <yq/tags.hpp>

YQ_TYPE_IMPLEMENT(yq::tachyon::Vertex³)

namespace yq::tachyon {
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
