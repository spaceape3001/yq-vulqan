////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IRangeWD.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PRangeWD.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IRangeʷD)

namespace yq::tachyon {
    void    IRangeʷD::init_meta()
    {
        auto w = writer<IRangeʷD>();
        w.description("W Range");
    }
}
