////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/interface/IMinSize1.hpp>

#include <tachyon/api/InterfaceMetaWriter.hpp>
#include <tachyon/proxy/PMinSize1.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IMinSize¹)

namespace yq::tachyon {
    void    IMinSize¹::init_meta()
    {
        auto w = writer<IMinSize¹>();
        w.description("1D Size");
    }
}
