////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ISize3D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PSize3D.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/shape/Size3.hxx>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ISize³D)

namespace yq::tachyon {
    void    ISize³D::size(add_k, const Vector3D&v)
    {
        size(ADD, Size3D(v));
    }

    void    ISize³D::init_meta()
    {
        auto w = writer<ISize³D>();
        w.description("3D Size");
    }
}
