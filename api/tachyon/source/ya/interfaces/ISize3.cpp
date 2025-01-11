////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/interfaces/ISize3.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <ya/proxies/PSize3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ISize³)

namespace yq::tachyon {
    void    ISize³::init_info()
    {
        auto w = writer<ISize³>();
        w.description("3D Size");
    }
}
