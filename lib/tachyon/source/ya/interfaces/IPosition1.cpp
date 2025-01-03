////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/interfaces/IPosition1.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <ya/proxies/PPosition1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition¹)

namespace yq::tachyon {
    void    IPosition¹::init_info()
    {
        auto w = writer<IPosition¹>();
        w.description("1D Position");
    }
}
