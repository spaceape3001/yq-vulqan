////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition1.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition¹)

namespace yq::tachyon {
    void    IPosition¹::init_info()
    {
        auto w = writer<IPosition¹>();
        w.description("1D Position");
    }
}
