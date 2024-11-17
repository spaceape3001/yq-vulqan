////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition4M.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition4M.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition4M)

namespace yq::tachyon {
    void    IPosition4M::init_info()
    {
        auto w = writer<IPosition4M>();
        w.description("4M Position");
    }
}
