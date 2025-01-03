////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/interfaces/IPosition2.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <ya/proxies/PPosition2.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition²)

namespace yq::tachyon {
    void    IPosition²::init_info()
    {
        auto w = writer<IPosition²>();
        w.description("2D Position");
    }
}
