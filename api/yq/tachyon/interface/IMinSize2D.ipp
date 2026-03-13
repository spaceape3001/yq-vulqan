////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IMinSize2D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PMinSize2D.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/shape/Size2.hxx>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMinSize²D)

namespace yq::tachyon {
    void    IMinSize²D::min_size(add_k, const Vector2D&v)
    {
        min_size(ADD, Size2D(v));
    }

    void    IMinSize²D::init_meta()
    {
        auto w = writer<IMinSize²D>();
        w.description("2D Size");
    }
}
