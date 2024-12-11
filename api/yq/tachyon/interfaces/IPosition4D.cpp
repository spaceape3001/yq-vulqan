////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition4D.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition4D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition4D)

namespace yq::tachyon {
    void    IPosition4D::init_info()
    {
        auto w = writer<IPosition4D>();
        w.description("4D Position");
    }
}
