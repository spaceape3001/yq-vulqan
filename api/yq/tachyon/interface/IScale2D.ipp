////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IScale2D.hpp"

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PScale2D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IScale²D)

namespace yq::tachyon {
    void    IScale²D::init_meta()
    {
        auto w = writer<IScale²D>();
        w.description("2D Scale");
    }
}
