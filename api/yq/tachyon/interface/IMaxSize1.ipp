////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IMaxSize1.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PMaxSize1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMaxSize¹)

namespace yq::tachyon {
    void    IMaxSize¹::init_meta()
    {
        auto w = writer<IMaxSize¹>();
        w.description("1D Size");
    }
}
