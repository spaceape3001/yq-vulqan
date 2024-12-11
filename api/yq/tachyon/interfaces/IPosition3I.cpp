////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition3I.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition3I.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition3I)

namespace yq::tachyon {
    void    IPosition3I::init_info()
    {
        auto w = writer<IPosition3I>();
        w.description("3I Position");
    }
}
