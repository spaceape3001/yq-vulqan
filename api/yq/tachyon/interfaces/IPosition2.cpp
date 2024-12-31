////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition2.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition2.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition2)

namespace yq::tachyon {
    void    IPosition2::init_info()
    {
        auto w = writer<IPosition2>();
        w.description("2D Position");
    }
}
