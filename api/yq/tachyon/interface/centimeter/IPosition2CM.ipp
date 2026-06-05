////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition2CM.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/centimeter/PPosition2CM.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition²CM)

namespace yq::tachyon {
    void    IPosition²CM::init_meta()
    {
        auto w = writer<IPosition²CM>();
        w.description("2D Position (meters)");
    }
}
