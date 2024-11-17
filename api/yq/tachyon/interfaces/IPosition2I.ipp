////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition2D.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition2D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition2D)

namespace yq::tachyon {
    void    IPosition2D::init_info()
    {
        auto w = writer<IPosition2D>();
        w.description("2D Position");
    }
}
