////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition3D.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition3D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition3D)

namespace yq::tachyon {
    void    IPosition3D::init_info()
    {
        auto w = writer<IPosition3D>();
        w.description("3D Position");
    }
}
