////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IMassKG.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PMassKG.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMassKG)

namespace yq::tachyon {
    void    IMassKG::init_meta()
    {
        auto w = writer<IMassKG>();
        w.description("Mass (KG)");
    }
}
