////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/ICount3U.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PCount3U.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ICount³U)

namespace yq::tachyon {
    void    ICount³U::init_meta()
    {
        auto w = writer<ICount³U>();
        w.description("3D Count");
    }
}
