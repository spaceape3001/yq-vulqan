////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/interfaces/IMaxSize2.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <ya/proxies/PMaxSize2.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMaxSize²)

namespace yq::tachyon {
    void    IMaxSize²::init_info()
    {
        auto w = writer<IMaxSize²>();
        w.description("2D Size");
    }
}
