////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition1M.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/physicsvk/proxy/meter/PPosition1M.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition¹M)

namespace yq::tachyon {
    void    IPosition¹M::init_meta()
    {
        auto w = writer<IPosition¹M>();
        w.description("1D Position");
    }
}
