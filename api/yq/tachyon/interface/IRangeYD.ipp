////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IRangeYD.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PRangeYD.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IRangeʸD)

namespace yq::tachyon {
    void    IRangeʸD::init_meta()
    {
        auto w = writer<IRangeʸD>();
        w.description("W Range");
    }
}
