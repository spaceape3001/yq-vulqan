////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IRangeXD.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PRangeXD.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IRangeˣD)

namespace yq::tachyon {
    void    IRangeˣD::init_meta()
    {
        auto w = writer<IRangeˣD>();
        w.description("W Range");
    }
}
