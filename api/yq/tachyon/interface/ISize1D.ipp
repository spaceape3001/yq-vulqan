////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ISize1D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PSize1D.hpp>
#include <yq/vector/Vector1.hpp>
#include <yq/shape/Size1.hxx>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ISize¹D)

namespace yq::tachyon {
    void    ISize¹D::size(add_k, const Vector1D&v)
    {
        size(ADD, Size1D(v));
    }
    
    void    ISize¹D::init_meta()
    {
        auto w = writer<ISize¹D>();
        w.description("1D Size");
    }
}
