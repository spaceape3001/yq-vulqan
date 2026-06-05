////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition2M.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/meter/PPosition2M.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition²M)

namespace yq::tachyon {
    void    IPosition²M::init_meta()
    {
        auto w = writer<IPosition²M>();
        w.description("2D Position (meters)");
    }
}
