////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IMinSize4D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PMinSize4D.hpp>
#include <yq/vector/Vector4.hpp>
#include <yq/shape/Size4.hxx>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMinSize⁴D)

namespace yq::tachyon {
    void    IMinSize⁴D::min_size(add_k, const Vector4D&v)
    {
        min_size(ADD, Size4D(v));
    }
    
    void    IMinSize⁴D::init_meta()
    {
        auto w = writer<IMinSize⁴D>();
        w.description("4D Size");
    }
}
