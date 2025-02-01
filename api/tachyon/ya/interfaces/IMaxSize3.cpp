////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/interfaces/IMaxSize3.hpp>

#include <yt/api/InterfaceInfoWriter.hpp>
#include <ya/proxies/PMaxSize3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMaxSize³)

namespace yq::tachyon {
    void    IMaxSize³::init_info()
    {
        auto w = writer<IMaxSize³>();
        w.description("3D Size");
    }
}
