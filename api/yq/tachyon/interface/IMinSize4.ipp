////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IMinSize4.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PMinSize4.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMinSize⁴)

namespace yq::tachyon {
    void    IMinSize⁴::init_meta()
    {
        auto w = writer<IMinSize⁴>();
        w.description("4D Size");
    }
}
