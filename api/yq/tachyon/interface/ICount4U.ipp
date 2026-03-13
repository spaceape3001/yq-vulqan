////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/ICount4U.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PCount4U.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ICount⁴U)

namespace yq::tachyon {
    void    ICount⁴U::init_meta()
    {
        auto w = writer<ICount⁴U>();
        w.description("4D Count");
    }
}
