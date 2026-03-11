////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IPosition4M.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition4M.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition⁴M)

namespace yq::tachyon {
    void    IPosition⁴M::init_meta()
    {
        auto w = writer<IPosition⁴M>();
        w.description("4D Position (meters)");
    }
}
