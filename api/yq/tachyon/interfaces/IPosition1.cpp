////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition1.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition1)

namespace yq::tachyon {
    void    IPosition1::init_info()
    {
        auto w = writer<IPosition1>();
        w.description("1D Position");
    }
}
