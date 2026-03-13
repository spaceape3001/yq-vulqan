////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IMaxSize1D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PMaxSize1D.hpp>
#include <yq/vector/Vector1.hpp>
#include <yq/shape/Size1.hxx>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMaxSize¹D)

namespace yq::tachyon {
    void    IMaxSize¹D::max_size(add_k, const Vector1D&v)
    {
        max_size(ADD,Size1D(v));
    }

    void    IMaxSize¹D::init_meta()
    {
        auto w = writer<IMaxSize¹D>();
        w.description("1D Size");
    }
}
