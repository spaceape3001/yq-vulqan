////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition3.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition3)

namespace yq::tachyon {
    void    IPosition3::init_info()
    {
        auto w = writer<IPosition3>();
        w.description("3D Position");
    }
}
