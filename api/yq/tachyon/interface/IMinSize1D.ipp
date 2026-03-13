////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IMinSize1D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PMinSize1D.hpp>
#include <yq/vector/Vector1.hpp>
#include <yq/shape/Size1.hxx>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMinSize¹D)

namespace yq::tachyon {
    void    IMinSize¹D::min_size(add_k, const Vector1D&v)
    {
        min_size(ADD, Size1D(v));
    }
    
    void    IMinSize¹D::init_meta()
    {
        auto w = writer<IMinSize¹D>();
        w.description("1D Size");
    }
}
