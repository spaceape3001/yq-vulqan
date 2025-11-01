////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/ISize2.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PSize2.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ISize²)

namespace yq::tachyon {
    void    ISize²::init_meta()
    {
        auto w = writer<ISize²>();
        w.description("2D Size");
    }
}
