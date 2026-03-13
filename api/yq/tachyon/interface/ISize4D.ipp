////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ISize4D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PSize4D.hpp>
#include <yq/vector/Vector4.hpp>
#include <yq/shape/Size4.hxx>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ISize⁴D)

namespace yq::tachyon {
    void    ISize⁴D::size(add_k, const Vector4D&v)
    {
        size(ADD, Size4D(v));
    }

    void    ISize⁴D::init_meta()
    {
        auto w = writer<ISize⁴D>();
        w.description("4D Size");
    }
}
