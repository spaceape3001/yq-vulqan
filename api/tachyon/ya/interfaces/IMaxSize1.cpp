////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/interfaces/IMaxSize1.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <ya/proxies/PMaxSize1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMaxSize¹)

namespace yq::tachyon {
    void    IMaxSize¹::init_info()
    {
        auto w = writer<IMaxSize¹>();
        w.description("1D Size");
    }
}
