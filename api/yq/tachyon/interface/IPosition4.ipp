////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IPosition4.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition4.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition⁴)

namespace yq::tachyon {
    void    IPosition⁴::init_meta()
    {
        auto w = writer<IPosition⁴>();
        w.description("4D Position");
    }
}
