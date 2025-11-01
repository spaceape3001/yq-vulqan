////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "IDrawMode.hpp"
#include <yq/tachyon/proxy/PDrawMode.hpp>
#include <yq/tachyon/api/InterfaceMetaWriter.hpp>

YQ_INTERFACE_IMPLEMENT(yq::tachyon::IDrawMode)

namespace yq::tachyon {
    IDrawMode::IDrawMode() = default;
    IDrawMode::~IDrawMode() = default;

    void IDrawMode::init_meta()
    {
        auto w = writer<IDrawMode>();
        w.description("DrawMode Interface");
    }
}
