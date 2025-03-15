////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/interfaces/IMaxSize4.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <ya/proxies/PMaxSize4.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMaxSize⁴)

namespace yq::tachyon {
    void    IMaxSize⁴::init_info()
    {
        auto w = writer<IMaxSize⁴>();
        w.description("4D Size");
    }
}
