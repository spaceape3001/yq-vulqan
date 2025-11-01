////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/ISize4.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PSize4.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ISize⁴)

namespace yq::tachyon {
    void    ISize⁴::init_meta()
    {
        auto w = writer<ISize⁴>();
        w.description("4D Size");
    }
}
