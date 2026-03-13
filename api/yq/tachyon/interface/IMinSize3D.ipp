////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IMinSize3D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PMinSize3D.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/shape/Size3.hxx>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMinSize³D)

namespace yq::tachyon {
    void    IMinSize³D::min_size(add_k, const Vector3D&v)
    {
        min_size(ADD, Size3D(v));
    }

    void    IMinSize³D::init_meta()
    {
        auto w = writer<IMinSize³D>();
        w.description("3D Size");
    }
}
