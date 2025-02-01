////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/interfaces/IMinSize1.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <ya/proxies/PMinSize1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMinSize¹)

namespace yq::tachyon {
    void    IMinSize¹::init_info()
    {
        auto w = writer<IMinSize¹>();
        w.description("1D Size");
    }
}
