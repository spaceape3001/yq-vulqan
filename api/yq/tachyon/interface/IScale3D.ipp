////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IScale3D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PScale3D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IScale³D)

namespace yq::tachyon {
    void    IScale³D::init_meta()
    {
        auto w = writer<IScale³D>();
        w.description("3D Scale");
    }
}
