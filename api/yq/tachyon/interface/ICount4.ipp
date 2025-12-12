////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/ICount4.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PCount4.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ICount⁴)

namespace yq::tachyon {
    void    ICount⁴::init_meta()
    {
        auto w = writer<ICount⁴>();
        w.description("4D Count");
    }
}
