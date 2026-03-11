////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IPosition3D.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition3D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition³D)

namespace yq::tachyon {
    void    IPosition³D::init_meta()
    {
        auto w = writer<IPosition³D>();
        w.description("3D Position (double)");
    }
}
