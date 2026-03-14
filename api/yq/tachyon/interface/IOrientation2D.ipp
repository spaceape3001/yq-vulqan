////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IOrientation2D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/POrientation2D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IOrientation²D)

namespace yq::tachyon {
    void    IOrientation²D::init_meta()
    {
        auto w = writer<IOrientation²D>();
        w.description("2D Orientation");
    }
}
