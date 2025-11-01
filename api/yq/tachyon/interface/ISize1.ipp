////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/ISize1.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PSize1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ISize¹)

namespace yq::tachyon {
    void    ISize¹::init_meta()
    {
        auto w = writer<ISize¹>();
        w.description("1D Size");
    }
}
