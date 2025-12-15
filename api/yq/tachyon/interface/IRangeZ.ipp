////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IRangeZ.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PRangeZ.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IRangeᶻ)

namespace yq::tachyon {
    void    IRangeᶻ::init_meta()
    {
        auto w = writer<IRangeᶻ>();
        w.description("W Range");
    }
}
