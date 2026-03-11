////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IPosition1D.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition1D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition¹D)

namespace yq::tachyon {
    void    IPosition¹D::init_meta()
    {
        auto w = writer<IPosition¹D>();
        w.description("1D Position");
    }
}
