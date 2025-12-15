////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IInnerTessellation2.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PInnerTessellation2.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IInnerTessellation²)

namespace yq::tachyon {
    void    IInnerTessellation²::init_meta()
    {
        auto w = writer<IInnerTessellation²>();
        w.description("2D Inner Tessellation");
    }
}
