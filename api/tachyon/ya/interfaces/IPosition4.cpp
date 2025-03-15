////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/interfaces/IPosition4.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <ya/proxies/PPosition4.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition⁴)

namespace yq::tachyon {
    void    IPosition⁴::init_info()
    {
        auto w = writer<IPosition⁴>();
        w.description("4D Position");
    }
}
