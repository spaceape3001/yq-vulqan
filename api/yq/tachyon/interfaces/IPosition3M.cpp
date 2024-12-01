////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition3M.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition3M.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition3M)

namespace yq::tachyon {
    void    IPosition3M::init_info()
    {
        auto w = writer<IPosition3M>();
        w.description("3M Position");
    }
}
