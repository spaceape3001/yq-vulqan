////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IPosition4D.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition4D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition⁴D)

namespace yq::tachyon {
    void    IPosition⁴D::init_meta()
    {
        auto w = writer<IPosition⁴D>();
        w.description("4D Position (doubles)");
    }
}
