////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition1I.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition1I.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition1I)

namespace yq::tachyon {
    void    IPosition1I::init_info()
    {
        auto w = writer<IPosition1I>();
        w.proxy<PPosition1I>();
    }
}
