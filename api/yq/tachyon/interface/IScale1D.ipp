////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IScale1D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PScale1D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IScale¹D)

namespace yq::tachyon {
    void    IScale¹D::init_meta()
    {
        auto w = writer<IScale¹D>();
        w.description("1D Scale");
    }
}
