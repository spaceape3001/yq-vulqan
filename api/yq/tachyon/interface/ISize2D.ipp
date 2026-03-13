////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ISize2D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PSize2D.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/shape/Size2.hxx>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ISize²D)

namespace yq::tachyon {
    void    ISize²D::size(add_k, const Vector2D&v)
    {
        size(ADD, Size2D(v));
    }
    
    void    ISize²D::init_meta()
    {
        auto w = writer<ISize²D>();
        w.description("2D Size");
    }
}
