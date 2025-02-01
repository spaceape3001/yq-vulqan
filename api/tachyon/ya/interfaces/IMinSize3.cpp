////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/interfaces/IMinSize3.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <ya/proxies/PMinSize3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMinSize³)

namespace yq::tachyon {
    void    IMinSize³::init_info()
    {
        auto w = writer<IMinSize³>();
        w.description("3D Size");
    }
}
