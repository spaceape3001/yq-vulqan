////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IRenderMode.hpp"
#include <yq/tachyon/proxy/PRenderMode.hpp>
#include <yq/tachyon/api/InterfaceMetaWriter.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IRenderMode)

namespace yq::tachyon {
    IRenderMode::IRenderMode() = default;
    IRenderMode::~IRenderMode() = default;

    void IRenderMode::init_meta()
    {
        auto w = writer<IRenderMode>();
        w.description("RenderMode Interface");
    }
}
