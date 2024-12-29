////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition².hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition².hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition²)

namespace yq::tachyon {
    void    IPosition²::init_info()
    {
        auto w = writer<IPosition²>();
        w.description("2D Position");
    }
}
