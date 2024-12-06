////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition1M.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition1M.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition1M)

namespace yq::tachyon {
    void    IPosition1M::init_info()
    {
        auto w = writer<IPosition1M>();
        w.description("1M Position");
    }
}
