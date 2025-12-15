////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IOuterTessellation4.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/POuterTessellation4.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IOuterTessellation⁴)

namespace yq::tachyon {
    void    IOuterTessellation⁴::init_meta()
    {
        auto w = writer<IOuterTessellation⁴>();
        w.description("4D Outer Tessellation");
    }
}
