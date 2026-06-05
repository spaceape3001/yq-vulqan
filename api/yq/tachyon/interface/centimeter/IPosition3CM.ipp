////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition3CM.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/centimeter/PPosition3CM.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition³CM)

namespace yq::tachyon {
    void    IPosition³CM::init_meta()
    {
        auto w = writer<IPosition³CM>();
        w.description("3D Position (meters)");
    }
}
