////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/interfaces/IScale1.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <ya/proxies/PScale1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IScale¹)

namespace yq::tachyon {
    void    IScale¹::init_info()
    {
        auto w = writer<IScale¹>();
        w.description("1D Scale");
    }
}
