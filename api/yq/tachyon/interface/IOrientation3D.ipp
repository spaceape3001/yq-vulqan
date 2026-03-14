////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IOrientation3D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/POrientation3D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IOrientation³D)

namespace yq::tachyon {
    void    IOrientation³D::init_meta()
    {
        auto w = writer<IOrientation³D>();
        w.description("3D Orientation");
    }
}
