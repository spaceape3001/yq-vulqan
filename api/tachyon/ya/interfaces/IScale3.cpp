////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/interfaces/IScale3.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <ya/proxies/PScale3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IScale³)

namespace yq::tachyon {
    void    IScale³::init_info()
    {
        auto w = writer<IScale³>();
        w.description("3D Scale");
    }
}
