////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/interface/IPosition2D.hpp>

#include <yq/tachyon/api/InterfaceMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition2D.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IPosition²D)

namespace yq::tachyon {
    void    IPosition²D::init_meta()
    {
        auto w = writer<IPosition²D>();
        w.description("2D Position (double)");
    }
}
