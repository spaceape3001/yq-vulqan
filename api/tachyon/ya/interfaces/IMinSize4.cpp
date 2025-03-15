////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/interfaces/IMinSize4.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <ya/proxies/PMinSize4.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMinSize⁴)

namespace yq::tachyon {
    void    IMinSize⁴::init_info()
    {
        auto w = writer<IMinSize⁴>();
        w.description("4D Size");
    }
}
