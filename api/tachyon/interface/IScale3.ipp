////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IScale3.hpp>

#include <tachyon/api/InterfaceMetaWriter.hpp>
#include <tachyon/proxy/PScale3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IScale³)

namespace yq::tachyon {
    void    IScale³::init_info()
    {
        auto w = writer<IScale³>();
        w.description("3D Scale");
    }
}
