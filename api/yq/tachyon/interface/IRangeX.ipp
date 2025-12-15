////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IRangeX.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PRangeX.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IRangeˣ)

namespace yq::tachyon {
    void    IRangeˣ::init_meta()
    {
        auto w = writer<IRangeˣ>();
        w.description("W Range");
    }
}
