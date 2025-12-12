////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/ICount3.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PCount3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ICount³)

namespace yq::tachyon {
    void    ICount³::init_meta()
    {
        auto w = writer<ICount³>();
        w.description("3D Count");
    }
}
