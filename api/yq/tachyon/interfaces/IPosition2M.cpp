////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition2M.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition2M.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition2M)

namespace yq::tachyon {
    void    IPosition2M::init_info()
    {
        auto w = writer<IPosition2M>();
        w.proxy<PPosition2M>();
    }
}
