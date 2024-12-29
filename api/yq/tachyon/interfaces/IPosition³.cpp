////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IPosition³.hpp"

#include <yq/tachyon/api/InterfaceInfoWriter.hpp>
#include <yq/tachyon/proxies/PPosition³.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition³)

namespace yq::tachyon {
    void    IPosition³::init_info()
    {
        auto w = writer<IPosition³>();
        w.description("3D Position");
    }
}
