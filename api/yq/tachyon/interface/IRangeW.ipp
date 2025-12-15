////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IRangeW.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PRangeW.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IRangeʷ)

namespace yq::tachyon {
    void    IRangeʷ::init_meta()
    {
        auto w = writer<IRangeʷ>();
        w.description("W Range");
    }
}
