////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IMaxSize4.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PMaxSize4.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMaxSize⁴)

namespace yq::tachyon {
    void    IMaxSize⁴::init_meta()
    {
        auto w = writer<IMaxSize⁴>();
        w.description("4D Size");
    }
}
