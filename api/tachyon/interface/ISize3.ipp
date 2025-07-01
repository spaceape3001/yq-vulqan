////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/ISize3.hpp>

#include <tachyon/api/InterfaceMetaWriter.hpp>
#include <tachyon/proxy/PSize3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ISize³)

namespace yq::tachyon {
    void    ISize³::init_info()
    {
        auto w = writer<ISize³>();
        w.description("3D Size");
    }
}
