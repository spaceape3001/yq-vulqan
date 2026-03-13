////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IMaxSize2D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PMaxSize2D.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/shape/Size2.hxx>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMaxSize²D)

namespace yq::tachyon {
    void    IMaxSize²D::max_size(add_k, const Vector2D&v)
    {
        max_size(ADD, Size2D(v));
    }

    void    IMaxSize²D::init_meta()
    {
        auto w = writer<IMaxSize²D>();
        w.description("2D Size");
    }
}
