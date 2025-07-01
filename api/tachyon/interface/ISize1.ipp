////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/ISize1.hpp>

#include <tachyon/api/InterfaceMetaWriter.hpp>
#include <tachyon/proxy/PSize1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::ISize¹)

namespace yq::tachyon {
    void    ISize¹::init_info()
    {
        auto w = writer<ISize¹>();
        w.description("1D Size");
    }
}
