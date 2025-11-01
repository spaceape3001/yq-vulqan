////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/ISize3.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PSize3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ISize³)

namespace yq::tachyon {
    void    ISize³::init_meta()
    {
        auto w = writer<ISize³>();
        w.description("3D Size");
    }
}
