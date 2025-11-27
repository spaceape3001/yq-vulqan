////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ITopology.hpp"
#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PTopology.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ITopology)

namespace yq::tachyon {
    void ITopology::init_meta()
    {
        auto w = writer<ITopology>();
        w.description("Topology interface");
    }
}
