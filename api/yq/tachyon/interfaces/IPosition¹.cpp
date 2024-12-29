////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition¹.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition¹.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition¹)

namespace yq::tachyon {
    void    IPosition¹::init_info()
    {
        auto w = writer<IPosition¹>();
        w.description("1D Position");
    }
}
