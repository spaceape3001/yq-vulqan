////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IRangeY.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PRangeY.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IRangeʸ)

namespace yq::tachyon {
    void    IRangeʸ::init_meta()
    {
        auto w = writer<IRangeʸ>();
        w.description("W Range");
    }
}
