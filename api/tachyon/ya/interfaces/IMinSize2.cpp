////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/interfaces/IMinSize2.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <ya/proxies/PMinSize2.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMinSize²)

namespace yq::tachyon {
    void    IMinSize²::init_info()
    {
        auto w = writer<IMinSize²>();
        w.description("2D Size");
    }
}
