////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/interfaces/ISize2.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <ya/proxies/PSize2.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ISize²)

namespace yq::tachyon {
    void    ISize²::init_info()
    {
        auto w = writer<ISize²>();
        w.description("2D Size");
    }
}
