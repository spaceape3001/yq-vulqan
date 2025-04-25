////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/ISize4.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <tachyon/proxy/PSize4.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ISize⁴)

namespace yq::tachyon {
    void    ISize⁴::init_info()
    {
        auto w = writer<ISize⁴>();
        w.description("4D Size");
    }
}
