////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition3M.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/physicsvk/proxy/meter/PPosition3M.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition³M)

namespace yq::tachyon {
    void    IPosition³M::init_meta()
    {
        auto w = writer<IPosition³M>();
        w.description("3D Position (meters)");
    }
}
