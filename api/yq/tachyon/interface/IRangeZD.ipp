////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IRangeZD.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PRangeZD.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IRangeᶻD)

namespace yq::tachyon {
    void    IRangeᶻD::init_meta()
    {
        auto w = writer<IRangeᶻD>();
        w.description("W Range");
    }
}
