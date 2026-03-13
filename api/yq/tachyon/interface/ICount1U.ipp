////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/ICount1U.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PCount1U.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ICount¹U)

namespace yq::tachyon {
    void    ICount¹U::init_meta()
    {
        auto w = writer<ICount¹U>();
        w.description("1D Count");
    }
}
