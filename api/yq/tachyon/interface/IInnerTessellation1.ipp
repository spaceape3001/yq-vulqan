////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IInnerTessellation1.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PInnerTessellation1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IInnerTessellation¹)

namespace yq::tachyon {
    void    IInnerTessellation¹::init_meta()
    {
        auto w = writer<IInnerTessellation¹>();
        w.description("1D Inner Tessellation");
    }
}
