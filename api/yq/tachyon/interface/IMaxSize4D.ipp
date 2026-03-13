////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IMaxSize4D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PMaxSize4D.hpp>
#include <yq/vector/Vector4.hpp>
#include <yq/shape/Size4.hxx>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMaxSize⁴D)

namespace yq::tachyon {
    void    IMaxSize⁴D::max_size(add_k, const Vector4D&v)
    {
        max_size(ADD, Size4D(v));
    }

    void    IMaxSize⁴D::init_meta()
    {
        auto w = writer<IMaxSize⁴D>();
        w.description("4D Size");
    }
}
