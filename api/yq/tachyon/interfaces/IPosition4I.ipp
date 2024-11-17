////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition4I.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition4I.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition4I)

namespace yq::tachyon {
    void    IPosition4I::init_info()
    {
        auto w = writer<IPosition4I>();
        w.description("4I Position");
    }
}
