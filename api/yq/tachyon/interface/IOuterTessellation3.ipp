////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IOuterTessellation3.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/POuterTessellation3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IOuterTessellation³)

namespace yq::tachyon {
    void    IOuterTessellation³::init_meta()
    {
        auto w = writer<IOuterTessellation³>();
        w.description("3D Outer Tessellation");
    }
}
