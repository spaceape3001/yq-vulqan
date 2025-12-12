////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/ICount1.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PCount1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ICount¹)

namespace yq::tachyon {
    void    ICount¹::init_meta()
    {
        auto w = writer<ICount¹>();
        w.description("1D Count");
    }
}
