////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition1D.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition1D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition1D)

namespace yq::tachyon {
    void    IPosition1D::init_info()
    {
        auto w = writer<IPosition1D>();
        w.proxy<PPosition1D>();
    }
}
