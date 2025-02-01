////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/interfaces/ISize1.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <ya/proxies/PSize1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ISize¹)

namespace yq::tachyon {
    void    ISize¹::init_info()
    {
        auto w = writer<ISize¹>();
        w.description("1D Size");
    }
}
