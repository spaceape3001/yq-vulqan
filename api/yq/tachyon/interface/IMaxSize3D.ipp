////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IMaxSize3D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PMaxSize3D.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/shape/Size3.hxx>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMaxSize³D)

namespace yq::tachyon {
    void    IMaxSize³D::max_size(add_k, const Vector3D&v)
    {
        max_size(ADD, Size3D(v));
    }

    void    IMaxSize³D::init_meta()
    {
        auto w = writer<IMaxSize³D>();
        w.description("3D Size");
    }
}
