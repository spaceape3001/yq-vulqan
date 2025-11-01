////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IMinSize3.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PMinSize3.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMinSize³)

namespace yq::tachyon {
    void    IMinSize³::init_meta()
    {
        auto w = writer<IMinSize³>();
        w.description("3D Size");
    }
}
