////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition2D.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition2I.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition2I)

namespace yq::tachyon {
    void    IPosition2I::init_info()
    {
        auto w = writer<IPosition2I>();
        w.description("2I Position");
    }
}
