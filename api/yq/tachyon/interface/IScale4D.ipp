////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IScale4D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PScale4D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IScale⁴D)

namespace yq::tachyon {
    void    IScale⁴D::init_meta()
    {
        auto w = writer<IScale⁴D>();
        w.description("4D Scale");
    }
}
